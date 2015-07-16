---
layout: post
title:  "svn使用说明"
date:   2015-07-15 13:10:36
categories: tools
sid:    svn_manual
---

#1.checkout
svn checkout http://XXX.XXX.XXX.XXX/svn/capp/trunk/terminal/ubuntu14 --username zhangsyi

#2.忽略文件
[How to ignore a directory with SVN](http://stackoverflow.com/questions/116074/how-to-ignore-a-directory-with-svn)		

[How do I ignore files in Subversion](http://stackoverflow.com/questions/86049/how-do-i-ignore-files-in-subversion)

+ 忽略.jpg文件 svn propset svn:ignore "*.jpg" . 
+ 查看忽略文件 svn propget svn:ignore .
+ 编辑多个忽略文件svn propedit svn:ignore .

添加忽略文件后不要使用svn add * 这会把忽略文件也加进去，可以使用svn add --force .

##2.1 使用tortoisesvn
在目录右键--properites--new--svn:global-ignores

#3.提交
svn commit -m 'XXXXX' --username zhangsyi

#4 从管理中删除特定目录
	find -name 'CMakeFiles' | xargs svn delete --keep-local