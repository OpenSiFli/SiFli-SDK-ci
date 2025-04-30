#!/usr/bin/env python3
# .gitlab/ci/trigger_github_action.py
# 自动检查哪些PR可以合并，并批量触发GitHub Actions

import os
import sys
import requests
import json

GITHUB_TOKEN = os.environ.get('GITHUB_TOKEN')
GITHUB_REPO = os.environ.get('GITHUB_REPO')  # 格式: owner/repo
GITHUB_WORKFLOW = os.environ.get('GITHUB_WORKFLOW', 'merge_prs.yml')  # workflow文件名
GITHUB_BRANCH = os.environ.get('GITHUB_BRANCH', 'main')

# 读取待处理PR编号列表
if not os.path.exists('pr_mr_map.json'):
    print('[ERROR] 未找到pr_mr_map.json，无法获取PR编号列表')
    sys.exit(1)
with open('pr_mr_map.json', 'r') as f:
    pr_mr_map = json.load(f)
pr_numbers = list(pr_mr_map.keys())

if not all([GITHUB_TOKEN, GITHUB_REPO, pr_numbers]):
    print('[ERROR] GITHUB_TOKEN, GITHUB_REPO, pr_numbers 必须设置')
    sys.exit(1)

headers = {
    'Authorization': f'token {GITHUB_TOKEN}',
    'Accept': 'application/vnd.github+json',
}

mergeable_prs = []
for pr_number in pr_numbers:
    pr_url = f'https://api.github.com/repos/{GITHUB_REPO}/pulls/{pr_number}'
    resp = requests.get(pr_url, headers=headers)
    if resp.status_code != 200:
        print(f'[WARN] 获取PR #{pr_number} 信息失败: {resp.text}')
        continue
    pr_data = resp.json()
    if pr_data.get('merged'):
        print(f'[INFO] PR #{pr_number} 已合并，跳过')
        continue
    if pr_data.get('mergeable'):
        mergeable_prs.append(pr_number)
    else:
        print(f'[INFO] PR #{pr_number} 当前不可合并，跳过')

if not mergeable_prs:
    print('[INFO] 没有可合并的PR，跳过触发GitHub Actions')
    sys.exit(0)

# 触发workflow_dispatch事件
url = f'https://api.github.com/repos/{GITHUB_REPO}/actions/workflows/{GITHUB_WORKFLOW}/dispatches'
data = {
    'ref': GITHUB_BRANCH,
    'inputs': {
        'pr_numbers': json.dumps(mergeable_prs)
    }
}

print(f'[INFO] 触发GitHub Actions workflow: {GITHUB_WORKFLOW}，可合并PR编号: {mergeable_prs}')
resp = requests.post(url, headers=headers, json=data)
if resp.status_code == 204:
    print('[INFO] workflow_dispatch 触发成功')
else:
    print(f'[ERROR] 触发失败，状态码: {resp.status_code}, 返回: {resp.text}')
    sys.exit(1)
