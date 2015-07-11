---
layout: post
title:  "flask使用说明"
date:   2015-06-27 15:21:12
categories: python
sid:    flask_learn
---
# 1. 开发环境搭建

## 1.1 安装flask
	echo "install pip"
	sudo apt-get install python-pip
	echo "使用阿里源安装flask"
	sudo pip install flask -i http://mirrors.aliyun.com/pypi/simple
查看flask版本

	import flask
	print(flask.__version__)

## 1.2 配置pycharm

### 1.2.1 html的tab设置2个字符

	File -> Default Settings -> Editor -> Code Style
	-> HTML 修改Tab size:2 Indent:2 Continuation indent:4

