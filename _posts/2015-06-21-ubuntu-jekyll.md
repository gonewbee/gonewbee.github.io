---
layout: post
title:  "ubuntu搭建jekyll"
date:   2015-06-21 15:21:12
categories: linux
sid:    linux_jekyll
---
## 1 安装 ##
环境：ubuntu 14.04

### 1.1 安装ruby2.0
	sudo apt-get install ruby2.0 ruby2.0-dev

### 1.2 更换gem源
	gem sources --remove https://rubygems.org/
	gem sources -a http://ruby.taobao.org/
	gem sources -l # 请确保只有 ruby.taobao.org

### 1.2 安装bundler
	sudo gem2.0 install bundler

### 1.3 安装Jekyll 
创建文件Gemfile，输入内容：

	source 'http://ruby.taobao.org/'
	gem 'github-pages'
执行：bundle install进行安装。

### 1.4 安装nodejs
	sudo apt-get install nodejs

## 运行 ##
	jekyll serve
