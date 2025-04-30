#!/usr/bin/env python3
import os
import sys
import requests
import json

GITHUB_TOKEN = os.environ.get('GITHUB_TOKEN')
REPO = os.environ.get('GITHUB_REPOSITORY')
PR_NUMBERS = os.environ.get('PR_NUMBERS')

if not all([GITHUB_TOKEN, REPO, PR_NUMBERS]):
    print('[ERROR] 缺少必要环境变量')
    sys.exit(1)

headers = {
    'Authorization': f'token {GITHUB_TOKEN}',
    'Accept': 'application/vnd.github+json',
}

try:
    pr_numbers = json.loads(PR_NUMBERS)
except Exception as e:
    print(f'[ERROR] 解析PR编号失败: {e}')
    sys.exit(1)

merged = []
for pr_number in pr_numbers:
    pr_url = f'https://api.github.com/repos/{REPO}/pulls/{pr_number}'
    pr_resp = requests.get(pr_url, headers=headers)
    if pr_resp.status_code != 200:
        print(f'[WARN] 获取PR #{pr_number} 信息失败: {pr_resp.text}')
        continue
    pr_data = pr_resp.json()
    if pr_data.get('merged'):
        print(f'[INFO] PR #{pr_number} 已合并，跳过')
        merged.append(pr_number)
        continue
    if not pr_data.get('mergeable'):
        print(f'[WARN] PR #{pr_number} 当前不可合并，跳过')
        continue
    merge_url = f'https://api.github.com/repos/{REPO}/pulls/{pr_number}/merge'
    merge_resp = requests.put(merge_url, headers=headers, json={
        'commit_title': f'Auto-merge PR #{pr_number} from GitLab CI',
        'merge_method': 'squash'
    })
    if merge_resp.status_code == 200:
        print(f'[INFO] PR #{pr_number} 合并成功')
        merged.append(pr_number)
    else:
        print(f'[WARN] PR #{pr_number} 合并失败: {merge_resp.text}')

with open('merged_prs.json', 'w') as f:
    json.dump(merged, f)
print(f'[INFO] 合并成功的PR编号: {merged}')