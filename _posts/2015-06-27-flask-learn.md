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

