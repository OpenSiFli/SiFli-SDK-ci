#!/usr/bin/env python3
# .gitlab/ci/close_merged_mrs.py
# 根据merged_prs.json和pr_mr_map.json自动关闭已合并的MR

import os
import sys
import json
import requests

GITLAB_TOKEN = os.environ.get('GITLAB_TOKEN')
GITLAB_PROJECT_ID = os.environ.get('GITLAB_PROJECT_ID')

if not all([GITLAB_TOKEN, GITLAB_PROJECT_ID]):
    print('[ERROR] 必须设置GITLAB_TOKEN, GITLAB_PROJECT_ID')
    sys.exit(1)

try:
    with open('merged_prs.json', 'r') as f:
        merged_prs = json.load(f)
    with open('pr_mr_map.json', 'r') as f:
        pr_mr_map = json.load(f)
except Exception as e:
    print(f'[ERROR] 读取合并结果或映射文件失败: {e}')
    sys.exit(1)

headers = {'PRIVATE-TOKEN': GITLAB_TOKEN}
closed = []
for pr_number in merged_prs:
    mr_id = pr_mr_map.get(str(pr_number)) or pr_mr_map.get(int(pr_number))
    if not mr_id:
        print(f'[WARN] 未找到PR #{pr_number} 对应的MR')
        continue
    url = f'https://gitlab.com/api/v4/projects/{GITLAB_PROJECT_ID}/merge_requests/{mr_id}/state_events'
    resp = requests.post(url, headers=headers, json={'state_event': 'close'})
    if resp.status_code == 201:
        print(f'[INFO] MR {mr_id} 已关闭')
        closed.append(mr_id)
    else:
        print(f'[WARN] 关闭MR {mr_id} 失败: {resp.text}')
print(f'[INFO] 已关闭MR: {closed}')
