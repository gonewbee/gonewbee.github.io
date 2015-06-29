---
layout: post
title:  "svn使用说明"
date:   2015-06-29 9:35:17
categories: tools
sid:    svn_manual
---
# 1. svn命令行

##1.1 检出co
	svn co http://XXXXX --username XXX

##1.2 查看状态
	svn status

##1.3 恢复对某个文件的修改
	svn revert XXX

##1.4 比较某个文件
	svn diff XXX

##1.5 将文件加入svn管理
	svn add XXX

##1.6 提交
	svn commit -m "描述" 
