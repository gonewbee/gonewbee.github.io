---
layout: post
title:  "git使用说明"
date:   2015-06-27 15:26:21
categories: tools
sid:    git_manual
---

# 1. 常用命令

## 1.1 查看某次提交的具体内容
	git log -p -1 XXXXX ##-p显示具体内容；-1显示一次提交
	git log --stat -1 XXXX  ##显示修改的文件列表

## 1.2 从远端check分支
	git checkout -b stable-1.1 origin/stable-1.1

## 1.3 恢复已删除commit

	$ git reflog
	$ git reset --hard <commitid>

## 1.4 stash保存当前的工作现场
保存当前的工作现场

	$ git stash
还原

	$ git stash list
	$ git stash pop
	
	$ git stash apply stash@{0}
	

# 2. git flow

## 2.1 init
	git flow init

## 2.2 新功能
	$ git flow feature start icon #启动开发新功能
	$ git flow feature finish icon #结束新功能开发，会将代码合并回develop

