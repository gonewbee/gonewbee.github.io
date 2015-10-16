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
	sed -i "s/old/new/g" test.txt #加-i会实际作用到文件

### 3.2 添加行
在文件最后添加一行： export WLOG_APPENDER="FILE"	

	sed -i '$a export WLOG_APPENDER=\"FILE\"' text.txt

### 3.3 删除行
+ 删除包含WLOG_APPENDER的行：sed -i '/WLOG_APPENDER/d' text.txt

## 4. 重启输入法
killall ibus-daemon // killall  杀死进程 ， ibus-daemon 进程名		

ibus-daemon -d // -d 后台运行 | &

## 5. 比较diff

### 5.1 比较文件夹
	#比较两个文件夹，只显示不同的文件名称，忽略.git文件夹
	diff -Nrq . ~/WorkSpaces/windows --exclude=.git

## 6. 注销ssh会话

	pkill -9 -t pts/0 

## 7. ip route设置默认网关

	ip route change default via 192.168.99.113 dev eth0

## 8. iptables ip转发

	# 开启ip转发功能
	echo "1" > /proc/sys/net/ipv4/ip_forward
	iptables -t nat -A POSTROUTING -s 192.168.7.0/24 -o eth0 -j MASQUERADE
