---
layout: post
title:  "linux常用命令"
date:   2015-06-21 13:13:26
categories: linux
sid:    linux_command
---
## 1. find grep

### 1.1 在某类文件中搜索
在当前目录查找包含"TEST"的".h"和".c"文件,在两个-name之间加-o

	find ./ -name '*.h' -o -name '*.c' | xargs grep 'TEST'

## 2. tar

### 2.1 tar压缩指定目录文件
加-p参数
	
	tar -czpvf Puhua.tar.gz Puhua/client/X11/xf_client.c Puhua/include/freerdp/freerdp.h

### 2.2 tar时忽略某些文件
	tar -czvf createdeb.tgz createdeb --exclude '*.tgz' --exclude '*.deb'

### 2.3 查看压缩内容
	tar -tvf createdeb.tgz

## 3. sed

### 3.1 替换内容	

## 4. 重启输入法
killall ibus-daemon // killall  杀死进程 ， ibus-daemon 进程名		

ibus-daemon -d // -d 后台运行 | &