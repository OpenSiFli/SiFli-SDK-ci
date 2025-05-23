/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2008-7-12      Bernard      the first version
 * 2010-06-09     Bernard      fix the end stub of heap
 *                             fix memory check in rt_realloc function
 * 2010-07-13     Bernard      fix RT_ALIGN issue found by kuronca
 * 2010-10-14     Bernard      fix rt_realloc issue when realloc a NULL pointer.
 * 2017-07-14     armink       fix rt_realloc issue when new size is 0
 */

/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *         Simon Goldschmidt
 *
 */

#include <rthw.h>
#include <rtthread.h>
#ifdef _MSC_VER
    #include <intrin.h>
#endif

#ifndef RT_USING_MEMHEAP_AS_HEAP

#define RT_MEM_BACKUP_OPT

#define RT_MEM_CONT_USED_BLOCK_LEN_FIELD_SIZE  (sizeof(rt_uint32_t))

/* #define RT_MEM_DEBUG */
#define RT_MEM_STATS

#if defined (RT_USING_HEAP) && defined (RT_USING_SMALL_MEM)
#ifdef RT_USING_HOOK
static void (*rt_malloc_hook)(void *ptr, rt_size_t size);
static void (*rt_free_hook)(void *ptr);

/**
 * @addtogroup Hook
 */

/**@{*/

/**
 * This function will set a hook function, which will be invoked when a memory
 * block is allocated from heap memory.
 *
 * @param hook the hook function
 */
__ROM_USED void rt_malloc_sethook(void (*hook)(void *ptr, rt_size_t size))
{
    rt_malloc_hook = hook;
}

/**
 * This function will set a hook function, which will be invoked when a memory
 * block is released to heap memory.
 *
 * @param hook the hook function
 */
__ROM_USED void rt_free_sethook(void (*hook)(void *ptr))
{
    rt_free_hook = hook;
}

/**@}*/

#endif

#define HEAP_MAGIC 0x1ea0
struct heap_mem
{
    /* magic and used flag */
    rt_uint16_t magic;
    rt_uint16_t used;

    rt_size_t next, prev;
    rt_uint32_t size;       /**< requested memory size excluding header*/
#ifdef RT_USING_MEMTRACE
#ifdef RT_MEM_RECORD_THREAD_NAME
    rt_uint8_t thread[4];   /**< thread name */
#endif  /* RT_MEM_RECORD_THREAD_NAME */
    rt_uint32_t ret_addr;
    rt_tick_t   tick;
#endif
};

/** pointer to the heap: for alignment, heap_ptr is now a pointer instead of an array */
static rt_uint8_t *heap_ptr;

/** the last entry, always unused! */
static struct heap_mem *heap_end;

#define MIN_SIZE 12
#define MIN_SIZE_ALIGNED     RT_ALIGN(MIN_SIZE, RT_ALIGN_SIZE)
#define SIZEOF_STRUCT_MEM    RT_ALIGN(sizeof(struct heap_mem), RT_ALIGN_SIZE)

static struct heap_mem *lfree;   /* pointer to the lowest free block */
static struct heap_mem *lused;   /* pointer to the highest used block */


static struct rt_semaphore heap_sem;
static rt_size_t mem_size_aligned;

#ifdef RT_MEM_STATS
    /** total memory size having been allocated, including header and padding bytes */
    static rt_size_t used_mem, max_mem;
    /** total memory size requested by user, excluding header and padding bytes */
    static rt_size_t actual_used_mem;
    /** max actual_used_mem ever happens */
    static rt_size_t actual_max_mem;
#endif
#ifdef RT_USING_MEMTRACE
#ifdef RT_MEM_RECORD_THREAD_NAME
rt_inline void rt_mem_setname(struct heap_mem *mem, const char *name)
{
    int index;
    for (index = 0; index < sizeof(mem->thread); index ++)
    {
        if (name[index] == '\0') break;
        mem->thread[index] = name[index];
    }

    for (; index < sizeof(mem->thread); index ++)
    {
        mem->thread[index] = ' ';
    }
}
#endif /* RT_MEM_RECORD_THREAD_NAME */
#endif

static void plug_holes(struct heap_mem *mem)
{
    struct heap_mem *nmem;
    struct heap_mem *pmem;

    RT_ASSERT((rt_uint8_t *)mem >= heap_ptr);
    RT_ASSERT((rt_uint8_t *)mem < (rt_uint8_t *)heap_end);
    RT_ASSERT(mem->used == 0);

    /* plug hole forward */
    nmem = (struct heap_mem *)&heap_ptr[mem->next];
    if (mem != nmem &&
            nmem->used == 0 &&
            (rt_uint8_t *)nmem != (rt_uint8_t *)heap_end)
    {
        /* if mem->next is unused and not end of heap_ptr,
         * combine mem and mem->next
         */
        if (lfree == nmem)
        {
            lfree = mem;
        }
        mem->next = nmem->next;
        ((struct heap_mem *)&heap_ptr[nmem->next])->prev = (rt_uint8_t *)mem - heap_ptr;
    }

    /* plug hole backward */
    pmem = (struct heap_mem *)&heap_ptr[mem->prev];
    if (pmem != mem && pmem->used == 0)
    {
        /* if mem->prev is unused, combine mem and mem->prev */
        if (lfree == mem)
        {
            lfree = pmem;
        }
        pmem->next = mem->next;
        ((struct heap_mem *)&heap_ptr[mem->next])->prev = (rt_uint8_t *)pmem - heap_ptr;
    }
}

static void update_highest_used(void)
{
    /* Find prev used block */
    while (!lused->used && ((rt_uint8_t *)lused != heap_ptr))
    {
        lused = (struct heap_mem *)&heap_ptr[lused->prev];
    }
    if (((rt_uint8_t *)lused == heap_ptr) && !lused->used)
    {
        lused = RT_NULL;
    }
}

static void init_heap_end(struct heap_mem *end)
{
    RT_ASSERT(end);

    end->magic = HEAP_MAGIC;
    end->used  = 1;
    end->next  = mem_size_aligned + SIZEOF_STRUCT_MEM;
    end->prev  = mem_size_aligned + SIZEOF_STRUCT_MEM;
#ifdef RT_USING_MEMTRACE
#ifdef RT_MEM_RECORD_THREAD_NAME
    rt_mem_setname(heap_end, "INIT");
#endif  /* RT_MEM_RECORD_THREAD_NAME */
#endif
}

static rt_uint32_t rt_mem_used_size(void)
{
    rt_uint32_t used_size;

    struct heap_mem *next;

    if (lused)
    {
        used_size = lused->next;
        next = (struct heap_mem *)&heap_ptr[lused->next];
        if ((rt_uint32_t)next < (rt_uint32_t)heap_end)
        {
            /* next should not be used */
            RT_ASSERT(0 == next->used);
            /* including header of the first unused block */
            used_size += SIZEOF_STRUCT_MEM;
        }
        else
        {
            /* next is heap_end, do nothing */
        }
    }
    else
    {
        /* including header of the first unused block */
        used_size = SIZEOF_STRUCT_MEM;
    }

    return used_size;
}



/**
 * @ingroup SystemInit
 *
 * This function will initialize system heap memory.
 *
 * @param begin_addr the beginning address of system heap memory.
 * @param end_addr the end address of system heap memory.
 */
__ROM_USED void rt_system_heap_init(void *begin_addr, void *end_addr)
{
    struct heap_mem *mem;
    rt_uint32_t begin_align = RT_ALIGN((rt_uint32_t)begin_addr, RT_ALIGN_SIZE);
    rt_uint32_t end_align = RT_ALIGN_DOWN((rt_uint32_t)end_addr, RT_ALIGN_SIZE);

    RT_DEBUG_NOT_IN_INTERRUPT;

    /* alignment addr */
    if ((end_align > (2 * SIZEOF_STRUCT_MEM)) &&
            ((end_align - 2 * SIZEOF_STRUCT_MEM) >= begin_align))
    {
        /* calculate the aligned memory size */
        mem_size_aligned = end_align - begin_align - 2 * SIZEOF_STRUCT_MEM;
    }
    else
    {
        rt_kprintf("mem init, error begin address 0x%x, and end address 0x%x\n",
                   (rt_uint32_t)begin_addr, (rt_uint32_t)end_addr);

        return;
    }

    /* point to begin address of heap */
    heap_ptr = (rt_uint8_t *)begin_align;

    RT_DEBUG_LOG(RT_DEBUG_MEM, ("mem init, heap begin address 0x%x, size %d\n",
                                (rt_uint32_t)heap_ptr, mem_size_aligned));

    /* initialize the start of the heap */
    mem        = (struct heap_mem *)heap_ptr;
    mem->magic = HEAP_MAGIC;
    mem->next  = mem_size_aligned + SIZEOF_STRUCT_MEM;
    mem->prev  = 0;
    mem->used  = 0;
#ifdef RT_USING_MEMTRACE
#ifdef RT_MEM_RECORD_THREAD_NAME
    rt_mem_setname(mem, "INIT");
#endif  /* RT_MEM_RECORD_THREAD_NAME */
#endif

    /* initialize the end of the heap */
    heap_end        = (struct heap_mem *)&heap_ptr[mem->next];
    init_heap_end(heap_end);

    rt_sem_init(&heap_sem, "heap", 1, RT_IPC_FLAG_FIFO);

    /* initialize the lowest-free pointer to the start of the heap */
    lfree = (struct heap_mem *)heap_ptr;
    /* initialize the highest-used pointer to NULL as no block is allocated yet */
    lused = RT_NULL;
}





/**
 * @addtogroup MM
 */

/**@{*/

/**
 * Allocate a block of memory with a minimum of 'size' bytes.
 *
 * @param size is the minimum size of the requested block in bytes.
 *
 * @return pointer to allocated memory or NULL if no free memory was found.
 */
__ROM_USED void *rt_malloc(rt_size_t size)
{
    rt_size_t ptr, ptr2;
    struct heap_mem *mem, *mem2;
    //static int assert_0 = 0;

    if (size == 0)
    {
        //RT_ASSERT(0);
        return RT_NULL;
    }

    RT_DEBUG_NOT_IN_INTERRUPT;

    if (size != RT_ALIGN(size, RT_ALIGN_SIZE))
        RT_DEBUG_LOG(RT_DEBUG_MEM, ("malloc size %d, but align to %d\n",
                                    size, RT_ALIGN(size, RT_ALIGN_SIZE)));
    else
        RT_DEBUG_LOG(RT_DEBUG_MEM, ("malloc size %d\n", size));

    /* alignment size */
    size = RT_ALIGN(size, RT_ALIGN_SIZE);

    if (size > mem_size_aligned)
    {
        RT_DEBUG_LOG(RT_DEBUG_MEM, ("no memory\n"));
        //RT_ASSERT(0);
        return RT_NULL;
    }

    /* every data block must be at least MIN_SIZE_ALIGNED long */
    if (size < MIN_SIZE_ALIGNED)
        size = MIN_SIZE_ALIGNED;

    /* take memory semaphore */
    rt_sem_take(&heap_sem, RT_WAITING_FOREVER);

    //rt_kprintf("heap_ptr %x lfree %x - %x\n", lfree, heap_ptr, (rt_uint8_t *)lfree - heap_ptr);
    for (ptr = (rt_uint8_t *)lfree - heap_ptr;
            ptr < mem_size_aligned - size;
            ptr = ((struct heap_mem *)&heap_ptr[ptr])->next)
    {
        mem = (struct heap_mem *)&heap_ptr[ptr];

        if ((!mem->used) && (mem->next - (ptr + SIZEOF_STRUCT_MEM)) >= size)
        {
            /* mem is not used and at least perfect fit is possible:
             * mem->next - (ptr + SIZEOF_STRUCT_MEM) gives us the 'user data size' of mem */

            if (mem->next - (ptr + SIZEOF_STRUCT_MEM) >=
                    (size + SIZEOF_STRUCT_MEM + MIN_SIZE_ALIGNED))
            {
                /* (in addition to the above, we test if another struct heap_mem (SIZEOF_STRUCT_MEM) containing
                 * at least MIN_SIZE_ALIGNED of data also fits in the 'user data space' of 'mem')
                 * -> split large block, create empty remainder,
                 * remainder must be large enough to contain MIN_SIZE_ALIGNED data: if
                 * mem->next - (ptr + (2*SIZEOF_STRUCT_MEM)) == size,
                 * struct heap_mem would fit in but no data between mem2 and mem2->next
                 * @todo we could leave out MIN_SIZE_ALIGNED. We would create an empty
                 *       region that couldn't hold data, but when mem->next gets freed,
                 *       the 2 regions would be combined, resulting in more free memory
                 */
                ptr2 = ptr + SIZEOF_STRUCT_MEM + size;

                /* create mem2 struct */
                mem2       = (struct heap_mem *)&heap_ptr[ptr2];
                mem2->magic = HEAP_MAGIC;
                mem2->used = 0;
                mem2->next = mem->next;
                mem2->prev = ptr;
#ifdef RT_USING_MEMTRACE
                /* record free block available */
                mem2->tick = rt_system_get_time();
#ifdef RT_MEM_RECORD_THREAD_NAME
                rt_mem_setname(mem2, "    ");
#endif  /* RT_MEM_RECORD_THREAD_NAME */
#endif

                /* and insert it between mem and mem->next */
                mem->next = ptr2;
                mem->used = 1;

                if (mem2->next != mem_size_aligned + SIZEOF_STRUCT_MEM)
                {
                    ((struct heap_mem *)&heap_ptr[mem2->next])->prev = ptr2;
                }
#ifdef RT_MEM_STATS
                used_mem += (size + SIZEOF_STRUCT_MEM);
                if (max_mem < used_mem)
                    max_mem = used_mem;
#endif
            }
            else
            {
                /* (a mem2 struct does no fit into the user data space of mem and mem->next will always
                 * be used at this point: if not we have 2 unused structs in a row, plug_holes should have
                 * take care of this).
                 * -> near fit or excact fit: do not split, no mem2 creation
                 * also can't move mem->next directly behind mem, since mem->next
                 * will always be used at this point!
                 */
                mem->used = 1;
#ifdef RT_MEM_STATS
                used_mem += mem->next - ((rt_uint8_t *)mem - heap_ptr);
                if (max_mem < used_mem)
                    max_mem = used_mem;
#endif
            }
#if defined(RT_MEM_STATS)
            actual_used_mem += size;
            if (actual_max_mem < actual_used_mem)
                actual_max_mem = actual_used_mem;
#endif

            /* set memory block magic */
            mem->magic = HEAP_MAGIC;
            mem->size = size;
#ifdef RT_USING_MEMTRACE
            mem->tick = rt_system_get_time();
#ifdef _MSC_VER
            mem->ret_addr = (rt_uint32_t) _ReturnAddress();
#else
            mem->ret_addr = (rt_uint32_t) __builtin_return_address(0);
#endif
#endif

#ifdef RT_USING_MEMTRACE
#ifdef RT_MEM_RECORD_THREAD_NAME
            if (rt_thread_self())
                rt_mem_setname(mem, rt_thread_self()->name);
            else
                rt_mem_setname(mem, "NONE");
#endif  /* RT_MEM_RECORD_THREAD_NAME */
#endif

            if (mem == lfree)
            {
                /* Find next free block after mem and update lowest free pointer */
                while (lfree->used && lfree != heap_end)
                    lfree = (struct heap_mem *)&heap_ptr[lfree->next];

                RT_ASSERT(((lfree == heap_end) || (!lfree->used)));
            }

            if ((rt_uint32_t)mem > (rt_uint32_t)lused)
            {
                lused = mem;
            }

            rt_sem_release(&heap_sem);
            RT_ASSERT((rt_uint32_t)mem + SIZEOF_STRUCT_MEM + size <= (rt_uint32_t)heap_end);
            RT_ASSERT((rt_uint32_t)((rt_uint8_t *)mem + SIZEOF_STRUCT_MEM) % RT_ALIGN_SIZE == 0);
            RT_ASSERT((((rt_uint32_t)mem) & (RT_ALIGN_SIZE - 1)) == 0);

            RT_DEBUG_LOG(RT_DEBUG_MEM,
                         ("allocate memory at 0x%x, size: %d\n",
                          (rt_uint32_t)((rt_uint8_t *)mem + SIZEOF_STRUCT_MEM),
                          (rt_uint32_t)(mem->next - ((rt_uint8_t *)mem - heap_ptr))));

            RT_OBJECT_HOOK_CALL(rt_malloc_hook,
                                (((void *)((rt_uint8_t *)mem + SIZEOF_STRUCT_MEM)), size));


            /* return the memory data except mem struct */
            return (rt_uint8_t *)mem + SIZEOF_STRUCT_MEM;
        }
#if 0
        else if (!mem->used && assert_0)
            rt_kprintf("get %d - %d\n", (mem->next - (ptr + SIZEOF_STRUCT_MEM)), size);
#endif
    }

    rt_sem_release(&heap_sem);

#if 0
    if (assert_0) RT_ASSERT(0);
    assert_0 = 1;
    rt_malloc(size);
#endif
    return RT_NULL;
}
RTM_EXPORT(rt_malloc);

/**
 * This function will change the previously allocated memory block.
 *
 * @param rmem pointer to memory allocated by rt_malloc
 * @param newsize the required new size
 *
 * @return the changed memory block address
 */
__ROM_USED void *rt_realloc(void *rmem, rt_size_t newsize)
{
    rt_size_t size;
    rt_size_t ptr, ptr2;
    struct heap_mem *mem, *mem2;
    void *nmem;

    RT_DEBUG_NOT_IN_INTERRUPT;

    /* alignment size */
    newsize = RT_ALIGN(newsize, RT_ALIGN_SIZE);
    if (newsize > mem_size_aligned)
    {
        RT_DEBUG_LOG(RT_DEBUG_MEM, ("realloc: out of memory\n"));

        return RT_NULL;
    }
    else if (newsize == 0)
    {
        rt_free(rmem);
        return RT_NULL;
    }

    /* allocate a new memory block */
    if (rmem == RT_NULL)
        return rt_malloc(newsize);

    rt_sem_take(&heap_sem, RT_WAITING_FOREVER);

    if ((rt_uint8_t *)rmem < (rt_uint8_t *)heap_ptr ||
            (rt_uint8_t *)rmem >= (rt_uint8_t *)heap_end)
    {
        /* illegal memory */
        rt_sem_release(&heap_sem);

        return rmem;
    }

    mem = (struct heap_mem *)((rt_uint8_t *)rmem - SIZEOF_STRUCT_MEM);

    ptr = (rt_uint8_t *)mem - heap_ptr;
    size = mem->next - ptr - SIZEOF_STRUCT_MEM;
    if (size == newsize)
    {
        /* the size is the same as */
        rt_sem_release(&heap_sem);

        return rmem;
    }

    if (newsize + SIZEOF_STRUCT_MEM + MIN_SIZE < size)
    {
        /* split memory block */
#ifdef RT_MEM_STATS
        used_mem -= (size - newsize);
        if (mem->size > newsize)
        {
            actual_used_mem -= (size - newsize);
        }
        else
        {
            actual_used_mem += (newsize - size);
        }
#endif

        ptr2 = ptr + SIZEOF_STRUCT_MEM + newsize;
        mem2 = (struct heap_mem *)&heap_ptr[ptr2];
        mem2->magic = HEAP_MAGIC;
        mem2->used = 0;
        mem2->next = mem->next;
        mem2->prev = ptr;
#ifdef RT_USING_MEMTRACE
        /* record free block available */
        mem2->tick = rt_system_get_time();
#ifdef RT_MEM_RECORD_THREAD_NAME
        rt_mem_setname(mem2, "    ");
#endif  /* RT_MEM_RECORD_THREAD_NAME */
#endif
        mem->next = ptr2;
        mem->size = newsize;

        if (mem2->next != mem_size_aligned + SIZEOF_STRUCT_MEM)
        {
            ((struct heap_mem *)&heap_ptr[mem2->next])->prev = ptr2;
        }

        /*rt_realloc may cause <lfree> change, if we don't change <lfree> timely, it may cause memory leakage*/
        if (mem2 < lfree)
        {
            /* the splited struct is now the lowest */
            lfree = mem2;
        }

        plug_holes(mem2);

        rt_sem_release(&heap_sem);

        return rmem;
    }
    rt_sem_release(&heap_sem);

    /* expand memory */
    nmem = rt_malloc(newsize);
    if (nmem != RT_NULL) /* check memory */
    {
        rt_memcpy(nmem, rmem, size < newsize ? size : newsize);
        rt_free(rmem);
    }

    return nmem;
}
RTM_EXPORT(rt_realloc);

/**
 * This function will contiguously allocate enough space for count objects
 * that are size bytes of memory each and returns a pointer to the allocated
 * memory.
 *
 * The allocated memory is filled with bytes of value zero.
 *
 * @param count number of objects to allocate
 * @param size size of the objects to allocate
 *
 * @return pointer to allocated memory / NULL pointer if there is an error
 */
__ROM_USED void *rt_calloc(rt_size_t count, rt_size_t size)
{
    void *p;

    /* allocate 'count' objects of size 'size' */
    p = rt_malloc(count * size);

    /* zero the memory */
    if (p)
        rt_memset(p, 0, count * size);

    return p;
}
RTM_EXPORT(rt_calloc);

/**
 * This function will release the previously allocated memory block by
 * rt_malloc. The released memory block is taken back to system heap.
 *
 * @param rmem the address of memory which will be released
 */
__ROM_USED void rt_free(void *rmem)
{
    struct heap_mem *mem;

    if (rmem == RT_NULL)
        return;

    RT_DEBUG_NOT_IN_INTERRUPT;

    RT_ASSERT((((rt_uint32_t)rmem) & (RT_ALIGN_SIZE - 1)) == 0);
    RT_ASSERT((rt_uint8_t *)rmem >= (rt_uint8_t *)heap_ptr &&
              (rt_uint8_t *)rmem < (rt_uint8_t *)heap_end);

    RT_OBJECT_HOOK_CALL(rt_free_hook, (rmem));

    if ((rt_uint8_t *)rmem < (rt_uint8_t *)heap_ptr ||
            (rt_uint8_t *)rmem >= (rt_uint8_t *)heap_end)
    {
        RT_DEBUG_LOG(RT_DEBUG_MEM, ("illegal memory\n"));

        return;
    }

    /* Get the corresponding struct heap_mem ... */
    mem = (struct heap_mem *)((rt_uint8_t *)rmem - SIZEOF_STRUCT_MEM);

    RT_DEBUG_LOG(RT_DEBUG_MEM,
                 ("release memory 0x%x, size: %d\n",
                  (rt_uint32_t)rmem,
                  (rt_uint32_t)(mem->next - ((rt_uint8_t *)mem - heap_ptr))));


    /* protect the heap from concurrent access */
    rt_sem_take(&heap_sem, RT_WAITING_FOREVER);

    /* ... which has to be in a used state ... */
    if (!mem->used || mem->magic != HEAP_MAGIC)
    {
        rt_kprintf("to free a bad data block:\n");
        rt_kprintf("mem: 0x%08x, used flag: %d, magic code: 0x%04x\n", mem, mem->used, mem->magic);
    }
    RT_ASSERT(mem->used);
    RT_ASSERT(mem->magic == HEAP_MAGIC);
    /* check whether this block of memory has been over-written. */
    RT_ASSERT(HEAP_MAGIC == ((struct heap_mem *)&heap_ptr[mem->next])->magic);

    /* ... and is now unused. */
    mem->used  = 0;
    mem->magic = HEAP_MAGIC;
#ifdef RT_USING_MEMTRACE
    /* record free time */
    mem->tick = rt_system_get_time();
#ifdef RT_MEM_RECORD_THREAD_NAME
    rt_mem_setname(mem, "    ");
#endif /* RT_MEM_RECORD_THREAD_NAME */
#endif

    if (mem < lfree)
    {
        /* the newly freed struct is now the lowest */
        lfree = mem;
    }

    if (mem == lused)
    {
        update_highest_used();
    }

#ifdef RT_MEM_STATS
    used_mem -= (mem->next - ((rt_uint8_t *)mem - heap_ptr));
    actual_used_mem -= mem->size;
#endif
    //rt_kprintf("rt_free: %p\n", rmem, rt_system_get_time());

    /* finally, see if prev or next are free also */
    plug_holes(mem);
    rt_sem_release(&heap_sem);
}
RTM_EXPORT(rt_free);

__ROM_USED rt_size_t rt_mem_size(void *rmem)
{
    struct heap_mem *mem;

    if (rmem == RT_NULL)
        return 0;

    RT_ASSERT((((rt_uint32_t)rmem) & (RT_ALIGN_SIZE - 1)) == 0);
    RT_ASSERT((rt_uint8_t *)rmem >= (rt_uint8_t *)heap_ptr &&
              (rt_uint8_t *)rmem < (rt_uint8_t *)heap_end);

    if ((rt_uint8_t *)rmem < (rt_uint8_t *)heap_ptr ||
            (rt_uint8_t *)rmem >= (rt_uint8_t *)heap_end)
    {
        RT_DEBUG_LOG(RT_DEBUG_MEM, ("illegal memory\n"));

        return 0;
    }

    /* Get the corresponding struct heap_mem ... */
    mem = (struct heap_mem *)((rt_uint8_t *)rmem - SIZEOF_STRUCT_MEM);

    RT_ASSERT(mem->used);
    RT_ASSERT(mem->magic == HEAP_MAGIC);

    return mem->size;
}
RTM_EXPORT(rt_mem_size);

#if 0
void rt_mem_used(rt_uint32_t *start_addr, rt_uint32_t *size)
{
    struct heap_mem *next;

    if (start_addr && size)
    {
        *start_addr = (rt_uint32_t)heap_ptr;
        if (lused)
        {
            *size = (rt_uint32_t)(lused->next) - (rt_uint32_t)heap_ptr;
            next = (struct heap_mem *)&heap_ptr[lused->next];
            if ((rt_uint32_t)next < (rt_uint32_t)heap_end)
            {
                /* next should not be used */
                RT_ASSERT(0 == next->used);
            }
        }
        else
        {
            *size = SIZEOF_STRUCT_MEM;
        }
    }
}
#endif

static rt_uint32_t rt_mem_backup_compress_copy(void *dst, const void *src, rt_ubase_t copy_size, rt_uint32_t max_size, rt_compressor_cb_t compressor_cb)
{
    rt_uint32_t actual_size;

    if (!compressor_cb)
    {
        if (copy_size <= max_size)
        {
            rt_memcpy((void *)dst, (void *)src, copy_size);
            actual_size = copy_size;
        }
        else
        {
            actual_size = 0;
        }
    }
    else
    {
        actual_size = compressor_cb((void *)dst, (void *)src, copy_size, max_size);
    }

    return actual_size;
}

static rt_uint32_t rt_mem_backup_decompress_copy(void *dst, const void *src, rt_ubase_t copy_size, rt_ubase_t max_size, rt_compressor_cb_t decompressor_cb)
{
    rt_uint32_t actual_size;

    if (!decompressor_cb)
    {
        rt_memcpy(dst, (void *)src, copy_size);
        actual_size = copy_size;
    }
    else
    {
        actual_size = decompressor_cb(dst, src, copy_size, max_size);
    }

    return actual_size;
}

static rt_uint32_t rt_mem_backup_contiguous_used_block(rt_uint8_t **buf, struct heap_mem *end_block, struct heap_mem *start_block,
        rt_uint32_t *max_size, rt_compressor_cb_t compressor_cb)
{
    rt_uint32_t copy_size;
    rt_uint8_t *dst;
    rt_uint32_t total_copy_size;
    rt_uint32_t remaining_size;

    dst = *buf;
    total_copy_size = 0;
    remaining_size = *max_size;
    /* copy contiguous used block */
    RT_ASSERT(start_block->used);
    RT_ASSERT((rt_uint32_t)end_block > (rt_uint32_t)start_block);
    if (end_block != heap_end)
    {
        RT_ASSERT(!end_block->used);
    }
    /****************************************************
     *  Format of backuped contiguous blocks
     *   1. header of the first used block
     *   2. length of following data (32bit)
     *   3. data in compressed or uncompressed format
     *
     ***************************************************/

    /* copy header first using uncompressed format */
    copy_size = rt_mem_backup_compress_copy((void *)dst, (void *)start_block, SIZEOF_STRUCT_MEM, remaining_size, RT_NULL);
    if (0 == copy_size)
    {
        return 0;
    }

    dst += copy_size;
    total_copy_size += copy_size;
    RT_ASSERT(remaining_size >= copy_size);
    remaining_size -= copy_size;
    if (remaining_size <= 4)
    {
        return 0;
    }

    /* compress remaining part, not including unused block header */
    copy_size = (rt_uint32_t)end_block - (rt_uint32_t)(start_block + 1);
    copy_size = rt_mem_backup_compress_copy((void *)(dst + RT_MEM_CONT_USED_BLOCK_LEN_FIELD_SIZE), (void *)(start_block + 1), copy_size, remaining_size - 4, compressor_cb);
    if (0 == copy_size)
    {
        return 0;
    }
    /* save length of compressed data */
    *(rt_uint32_t *)dst = copy_size;
    /* plus len */
    copy_size += RT_MEM_CONT_USED_BLOCK_LEN_FIELD_SIZE;
    copy_size = RT_ALIGN(copy_size, RT_ALIGN_SIZE);
    if (remaining_size < copy_size)
    {
        return 0;
    }
    dst += copy_size;
    total_copy_size += copy_size;
    remaining_size -= copy_size;

    *max_size = remaining_size;
    *buf = dst;
    return total_copy_size;
}



__ROM_USED rt_err_t rt_mem_backup(rt_uint8_t *buf, rt_uint32_t max_size, rt_uint32_t *used_size, rt_compressor_cb_t compressor_cb)
{
    rt_uint32_t copy_size;
#ifdef RT_MEM_BACKUP_OPT
    rt_uint32_t total_used_size;
    struct heap_mem *block;
    struct heap_mem *start_block;
#endif /* RT_MEM_BACKUP_OPT */

    if (!buf || !used_size)
    {
        return RT_ERROR;
    }

#ifndef RT_MEM_BACKUP_OPT
    copy_size = rt_mem_used_size();

    *used_size = rt_mem_backup_compress_copy((void *)buf, (void *)heap_ptr, copy_size, max_size, compressor_cb);
    if (0 == *used_size)
    {
        return RT_EFULL;
    }
#else
    total_used_size = 0;

    block = (struct heap_mem *)heap_ptr;
    start_block = RT_NULL;
    while (block < heap_end)
    {
        if (block->used)
        {
            if (!start_block)
            {
                start_block = block;
            }
        }
        else
        {
            if (start_block)
            {
                copy_size = rt_mem_backup_contiguous_used_block(&buf, block, start_block, &max_size, compressor_cb);
                if (0 == copy_size)
                {
                    return RT_EFULL;

                }
                total_used_size += copy_size;
                start_block = RT_NULL;

            }

            /* copy uncompressed header of unused block */
            copy_size = rt_mem_backup_compress_copy((void *)buf, block, SIZEOF_STRUCT_MEM, max_size, RT_NULL);
            if (0 == copy_size)
            {
                return RT_EFULL;
            }
            buf += copy_size;
            total_used_size += copy_size;
            RT_ASSERT(max_size >= copy_size);
            max_size -= copy_size;
        }
        block = (struct heap_mem *)&heap_ptr[block->next];
    }

    if (start_block)
    {
        copy_size = rt_mem_backup_contiguous_used_block(&buf, block, start_block, &max_size, compressor_cb);
        if (0 == copy_size)
        {
            return RT_EFULL;
        }
        total_used_size += copy_size;
        start_block = RT_NULL;
    }

    *used_size = total_used_size;
#endif

    return RT_EOK;

}


__ROM_USED rt_err_t rt_mem_restore(void *instance, rt_uint8_t *buf, rt_uint32_t size, rt_compressor_cb_t decompressor_cb)
{
    rt_uint32_t wr_size;
    rt_uint32_t max_size;
#ifdef RT_MEM_BACKUP_OPT
    rt_uint32_t copy_size;
    struct heap_mem *wr;
    rt_uint32_t rd_size;
#endif /* RT_MEM_BACKUP_OPT */

    if (!buf)
    {
        return RT_ERROR;
    }

#ifndef RT_MEM_BACKUP_OPT
    max_size = (rt_uint32_t)heap_end - (rt_uint32_t)heap_ptr;
    wr_size = rt_mem_backup_decompress_copy((void *)heap_ptr, (void *)buf, size, max_size, decompressor_cb);
    RT_ASSERT(wr_size > 0);

    RT_ASSERT(((rt_uint32_t)heap_ptr + wr_size) <= (rt_uint32_t)heap_end);
#else
    wr = (struct heap_mem *)heap_ptr;
    rd_size = 0;
    wr_size = 0;
    while (rd_size < size)
    {
        /* copy header in uncompressed foramt */
        copy_size = SIZEOF_STRUCT_MEM;
        if (((rt_uint8_t *)wr + copy_size) > (rt_uint8_t *)heap_end)
        {
            return RT_ERROR;
        }
        max_size = (rt_uint32_t)heap_end - (rt_uint32_t)wr;
        wr_size = rt_mem_backup_decompress_copy((void *)wr, (void *)buf, copy_size, max_size, RT_NULL);
        RT_ASSERT(wr_size == copy_size);
        rd_size += copy_size;
        buf += copy_size;
        if (HEAP_MAGIC != wr->magic)
        {
            return RT_ERROR;
        }

        if (wr->used)
        {
            /* copy remaining part */

            copy_size = *(rt_uint32_t *)buf;

            /* skip size field */
            rd_size += RT_MEM_CONT_USED_BLOCK_LEN_FIELD_SIZE;
            buf += RT_MEM_CONT_USED_BLOCK_LEN_FIELD_SIZE;

            max_size = (rt_uint32_t)heap_end - (rt_uint32_t)(wr + 1);
            wr_size = rt_mem_backup_decompress_copy((void *)(wr + 1), (void *)buf, copy_size, max_size, decompressor_cb);
            RT_ASSERT(wr_size > 0);
            copy_size = RT_ALIGN(copy_size, RT_ALIGN_SIZE);
            rd_size += copy_size;
            buf += copy_size;
            wr = (struct heap_mem *)((rt_uint32_t)(wr + 1) + wr_size);
            if ((rt_uint32_t)wr > (rt_uint32_t)heap_end)
            {
                return RT_ERROR;
            }
        }
        else
        {
            /* unused block use next pointer directly */
            wr = (struct heap_mem *)&heap_ptr[wr->next];
        }
    }
#endif

    /* reinit heap end */
    init_heap_end(heap_end);

    return RT_EOK;
}

__ROM_USED rt_uint32_t rt_mem_base(void)
{
    return (rt_uint32_t)heap_ptr;
}

__ROM_USED rt_uint32_t rt_mem_tail(void)
{
    return (rt_uint32_t)heap_end;
}

__ROM_USED rt_uint32_t rt_mem_header_size(void)
{
    return sizeof(struct heap_mem);
}

__ROM_USED rt_uint8_t rt_mem_header(void *ptr)
{
    return (heap_ptr <= (rt_uint8_t *) ptr && (rt_uint8_t *) ptr < heap_ptr + mem_size_aligned) ? 1 : 0;
}

__ROM_USED rt_uint32_t rt_mem_ret_addr_offset(void)
{
#ifdef RT_USING_MEMTRACE
    return sizeof(struct heap_mem) - (unsigned long)(&((struct heap_mem *)0)->ret_addr);
#else
    return 0;
#endif
}

#ifdef RT_MEM_STATS
__ROM_USED void rt_memory_info(rt_uint32_t *total,
                               rt_uint32_t *used,
                               rt_uint32_t *max_used)
{
    if (total != RT_NULL)
        *total = mem_size_aligned;
    if (used  != RT_NULL)
        *used = used_mem;
    if (max_used != RT_NULL)
        *max_used = max_mem;
}

#ifdef RT_USING_FINSH
    #include <finsh.h>
#endif

__ROM_USED void list_mem(void)
{
    rt_kprintf("total memory: %d ", mem_size_aligned);
    rt_kprintf("used memory : %d ", used_mem);
    rt_kprintf("maximum allocated memory: %d\n", max_mem);
    //rt_kprintf("actual used memory : %d ", actual_used_mem);
    //rt_kprintf("maximum actual allocated memory: %d\n", actual_max_mem);
}
MSH_CMD_EXPORT(list_mem, list memory usage information)

rt_uint32_t used_sram_size(void)
{
    return actual_used_mem;
}

rt_uint32_t max_sram_size(void)
{
    return mem_size_aligned;
}



#ifdef RT_USING_MEMTRACE
__ROM_USED int memcheck(void)
{
    int position;
    rt_uint32_t level;
    struct heap_mem *mem;
    level = rt_hw_interrupt_disable();
    for (mem = (struct heap_mem *)heap_ptr; mem != heap_end; mem = (struct heap_mem *)&heap_ptr[mem->next])
    {
        position = (rt_uint32_t)mem - (rt_uint32_t)heap_ptr;
        if (position < 0) goto __exit;
        if (position > mem_size_aligned) goto __exit;
        if (mem->magic != HEAP_MAGIC) goto __exit;
        if (mem->used != 0 && mem->used != 1) goto __exit;
    }
    rt_hw_interrupt_enable(level);

    return 0;
__exit:
    rt_kprintf("Memory block wrong:\n");
    rt_kprintf("address: 0x%08x\n", mem);
    rt_kprintf("  magic: 0x%04x\n", mem->magic);
    rt_kprintf("   used: %d\n", mem->used);
    rt_kprintf("  size: %d\n", mem->next - position - SIZEOF_STRUCT_MEM);
    rt_hw_interrupt_enable(level);

    return 0;
}
MSH_CMD_EXPORT(memcheck, check memory data);

__ROM_USED int memtrace(int argc, char **argv)
{
    struct heap_mem *mem;

    list_mem();

    rt_kprintf("\nmemory heap address:\n");
    rt_kprintf("heap_ptr: 0x%08x\n", heap_ptr);
    rt_kprintf("lfree   : 0x%08x\n", lfree);
    rt_kprintf("heap_end: 0x%08x\n", heap_end);

    rt_kprintf("\n--memory item information --\n");
    for (mem = (struct heap_mem *)heap_ptr; mem != heap_end; mem = (struct heap_mem *)&heap_ptr[mem->next])
    {
        int position = (rt_uint32_t)mem - (rt_uint32_t)heap_ptr;
        int size;

        rt_kprintf("[0x%08x - ", mem);

        size = mem->next - position - SIZEOF_STRUCT_MEM;
        if (size < 1024)
            rt_kprintf("%5d", size);
        else if (size < 1024 * 1024)
            rt_kprintf("%4dK", size / 1024);
        else
            rt_kprintf("%4dM", size / (1024 * 1024));
#ifdef RT_MEM_RECORD_THREAD_NAME
        rt_kprintf("] %c%c%c%c", mem->thread[0], mem->thread[1], mem->thread[2], mem->thread[3]);
#else
        rt_kprintf("]");
#endif /* RT_MEM_RECORD_THREAD_NAME */

        rt_kprintf(" 0x%08x", mem->ret_addr);
        rt_kprintf(" 0x%08x", mem->next);

        rt_kprintf(" %d", mem->used);
        rt_kprintf(" %-20d", mem->tick);

        if (mem->magic != HEAP_MAGIC)
            rt_kprintf(": ***\n");
        else
            rt_kprintf("\n");
    }

    return 0;
}
MSH_CMD_EXPORT(memtrace, dump memory trace information);
#endif /* end of RT_USING_MEMTRACE */
//#endif /* end of RT_USING_FINSH    */

#endif

/**@}*/

#endif /* end of RT_USING_HEAP */
#endif /* end of RT_USING_MEMHEAP_AS_HEAP */
