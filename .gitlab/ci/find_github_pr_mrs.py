#!/usr/bin/env python3
# .gitlab/ci/find_github_pr_mrs.py
# 查找所有未合并且标题带有 (GitHub PR) 的MR，并触发GitHub Action批量合并

import os
import sys
import requests
import json

GITLAB_TOKEN = os.environ.get('GITLAB_TOKEN')
GITLAB_PROJECT_ID = os.environ.get('GITLAB_PROJECT_ID')
GITHUB_TOKEN = os.environ.get('GITHUB_TOKEN')
GITHUB_REPO = os.environ.get('GITHUB_REPO')  # owner/repo
GITHUB_WORKFLOW = os.environ.get('GITHUB_WORKFLOW', 'merge_prs.yml')
GITHUB_BRANCH = os.environ.get('GITHUB_BRANCH', 'main')

if not all([GITLAB_TOKEN, GITLAB_PROJECT_ID, GITHUB_TOKEN, GITHUB_REPO]):
    print('[ERROR] 必须设置GITLAB_TOKEN, GITLAB_PROJECT_ID, GITHUB_TOKEN, GITHUB_REPO')
    sys.exit(1)

headers = {'PRIVATE-TOKEN': GITLAB_TOKEN}
# 获取所有open的MR
mrs_url = f'https://gitlab.com/api/v4/projects/{GITLAB_PROJECT_ID}/merge_requests?state=opened&per_page=100'
resp = requests.get(mrs_url, headers=headers)
if resp.status_code != 200:
    print(f'[ERROR] 获取MR失败: {resp.text}')
    sys.exit(1)

pr_numbers = []
mr_map = {}  # pr_number -> mr_id
for mr in resp.json():
    title = mr['title']
    if title.endswith('(GitHub PR)'):
        # 假设PR号在source_branch如 pr-123
        source_branch = mr['source_branch']
        if source_branch.startswith('pr-'):
            pr_number = source_branch.split('-')[1]
            pr_numbers.append(pr_number)
            mr_map[pr_number] = mr['iid']

if not pr_numbers:
    print('[INFO] 没有需要同步的GitHub PR MR')
    sys.exit(0)

print(f'[INFO] 待合并PR编号: {pr_numbers}')

# 触发GitHub Action
headers_gh = {
    'Authorization': f'token {GITHUB_TOKEN}',
    'Accept': 'application/vnd.github+json',
}
url = f'https://api.github.com/repos/{GITHUB_REPO}/actions/workflows/{GITHUB_WORKFLOW}/dispatches'
data = {
    'ref': GITHUB_BRANCH,
    'inputs': {
        'pr_numbers': json.dumps(pr_numbers)
    }
}
resp_gh = requests.post(url, headers=headers_gh, json=data)
if resp_gh.status_code == 204:
    print('[INFO] GitHub Actions workflow_dispatch 触发成功')
    # 保存pr->mr映射，供后续关闭MR用
    with open('pr_mr_map.json', 'w') as f:
        json.dump(mr_map, f)
else:
    print(f'[ERROR] 触发GitHub Action失败: {resp_gh.status_code}, {resp_gh.text}')
    sys.exit(1)
