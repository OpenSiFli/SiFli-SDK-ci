#!/usr/bin/env python3
# .gitlab/ci/trigger_github_action.py
# 用于通过GitHub API触发GitHub Actions workflow_dispatch

import os
import sys
import requests

GITHUB_TOKEN = os.environ.get('GITHUB_TOKEN')
GITHUB_REPO = os.environ.get('GITHUB_REPO')  # 格式: owner/repo
GITHUB_WORKFLOW = os.environ.get('GITHUB_WORKFLOW', 'merge_pr.yml')  # workflow文件名
GITHUB_PR_NUMBER = os.environ.get('GITHUB_PR_NUMBER')  # 需要合并的PR号
GITHUB_BRANCH = os.environ.get('GITHUB_BRANCH', 'main')

if not all([GITHUB_TOKEN, GITHUB_REPO, GITHUB_PR_NUMBER]):
    print('[ERROR] GITHUB_TOKEN, GITHUB_REPO, GITHUB_PR_NUMBER 必须设置')
    sys.exit(1)

headers = {
    'Authorization': f'token {GITHUB_TOKEN}',
    'Accept': 'application/vnd.github+json',
}

# 触发workflow_dispatch事件
url = f'https://api.github.com/repos/{GITHUB_REPO}/actions/workflows/{GITHUB_WORKFLOW}/dispatches'
data = {
    'ref': GITHUB_BRANCH,
    'inputs': {
        'pr_number': GITHUB_PR_NUMBER
    }
}

print(f'[INFO] 触发GitHub Actions workflow: {GITHUB_WORKFLOW}，PR号: {GITHUB_PR_NUMBER}')
resp = requests.post(url, headers=headers, json=data)
if resp.status_code == 204:
    print('[INFO] workflow_dispatch 触发成功')
else:
    print(f'[ERROR] 触发失败，状态码: {resp.status_code}, 返回: {resp.text}')
    sys.exit(1)
