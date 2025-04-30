#!/bin/bash
# .gitlab/ci/sync_to_github.sh
# 用于将GitLab主分支强制推送到GitHub

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

echo "[INFO] 开始将GitLab分支 $BRANCH 推送到GitHub仓库 $GITHUB_REPO"

git config --global user.email "si-bot@sifli.com"
git config --global user.name "SiFli-bot"

git remote add github-auth "https://${GITHUB_TOKEN}@github.com/${GITHUB_REPO}"
git fetch origin "$BRANCH"
git push github-auth "$BRANCH:$BRANCH" --force

echo "[INFO] 推送完成"
