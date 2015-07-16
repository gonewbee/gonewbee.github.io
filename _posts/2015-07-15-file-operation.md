---
layout: post
title:  "c/qt/python文件操作"
date:   2015-07-15 21:04:06
categories: tools
sid:    file_operation
---

#1. C语言

##1.1 用户根目录
[获取用户根目录](https://github.com/zhangshy/myTest/blob/master/linuxc/envParam/getHomePath.c)

使用getpwuid获取用户根目录

	struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    fprintf(stdout, "当前用户根目录：%s\n", homedir);

##1.2 当前目录
使用getcwd获取当前目录

	char current_path[MAXPATHLEN] = {0};
    if (getcwd(current_path, MAXPATHLEN)) {
        //使用getcwd获取当前工作路径
        fprintf(stdout, "当前工作路径：%s\n", current_path);
    }

##1.3 文件操作
[文件操作](https://github.com/zhangshy/myTest/blob/master/linuxc/envParam/fileDir.c)		

+ 判断目录/文件是否存在：stat(dir, &st)
+ 判断文件是否存在access
+ 新建目录：mkdir(dir, mode)

#2 python
[获取目录](https://github.com/zhangshy/myTest/blob/master/python/envParam/filePath.py)

	home_path = os.path.expanduser("~") #获取用户根目录
	file_path = os.path.abspath(__file__) #文件的绝对路径
	parent_path = os.path.dirname(file_path) #获取file_path的父目录
	current_path = os.getcwd() #当前路径

#3 qt
获取用户根目录 QDir::homePath()

