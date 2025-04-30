#!/usr/bin/env python3
# .gitlab/ci/finish.py
# 用于同步流程收尾，如解锁MR、通知团队等

import os
import sys
import requests

def unlock_merge_requests():
    # 示例：调用GitLab API批量解锁MR（需根据实际API和权限实现）
    GITLAB_TOKEN = os.environ.get('GITLAB_TOKEN')
    GITLAB_PROJECT_ID = os.environ.get('GITLAB_PROJECT_ID')
    if not GITLAB_TOKEN or not GITLAB_PROJECT_ID:
        print('[WARN] 未设置GITLAB_TOKEN或GITLAB_PROJECT_ID，跳过解锁MR')
        return
    headers = {'PRIVATE-TOKEN': GITLAB_TOKEN}
    # 这里只做示例，实际应根据标签、状态等筛选MR
    url = f'https://gitlab.com/api/v4/projects/{GITLAB_PROJECT_ID}/merge_requests?state=locked'
    resp = requests.get(url, headers=headers)
    if resp.status_code != 200:
        print(f'[WARN] 获取MR失败: {resp.text}')
        return
    for mr in resp.json():
        mr_id = mr['iid']
        unlock_url = f'https://gitlab.com/api/v4/projects/{GITLAB_PROJECT_ID}/merge_requests/{mr_id}/unlock'
        unlock_resp = requests.post(unlock_url, headers=headers)
        if unlock_resp.status_code == 200:
            print(f'[INFO] MR {mr_id} 已解锁')
        else:
            print(f'[WARN] 解锁MR {mr_id} 失败: {unlock_resp.text}')

def main():
    print('[INFO] 开始收尾流程...')
    unlock_merge_requests()
    print('[INFO] 收尾流程完成')

if __name__ == '__main__':
    main()
