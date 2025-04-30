#!/bin/bash
# .gitlab/ci/sync_from_github.sh
# 用于将GitHub主分支同步回GitLab

set -e

# 需要提前在CI变量中配置以下环境变量：
# GITLAB_BRANCH: 需要同步的分支名（如main/master）
# GITHUB_REPO: GitHub仓库地址（如https://github.com/yourorg/yourrepo.git）
# GITHUB_TOKEN: GitHub访问Token

BRANCH="${GITLAB_BRANCH:-main}"
GITHUB_REPO="${GITHUB_REPO}"
GITHUB_TOKEN="${GITHUB_TOKEN}"

if [[ -z "$GITHUB_REPO" || -z "$GITHUB_TOKEN" ]]; then
  echo "[ERROR] GITHUB_REPO 或 GITHUB_TOKEN 未设置，无法同步！"
  exit 1
fi

echo "[INFO] 开始从GitHub仓库 $GITHUB_REPO 拉取分支 $BRANCH 到本地"

git config --global user.email "ci-bot@example.com"
git config --global user.name "ci-bot"

git remote add github-auth "https://${GITHUB_TOKEN}@${GITHUB_REPO#https://}"
git fetch github-auth "$BRANCH"
git checkout "$BRANCH"
git reset --hard "github-auth/$BRANCH"
git push origin "$BRANCH" --force

echo "[INFO] GitHub主分支同步到GitLab完成"
