---
layout: post
title:  "windows命令行"
date:   2015-08-04 19:53:14
categories: windows
sid:    windows_cmd
---

#1. session

##1.1 切换session
[tscon](https://support.microsoft.com/en-us/kb/321703)	

	tscon SessionID

##1.2 查看session
query

	C:\Users\Administrator>query user
	 用户名                会话名             ID  状态    空闲时间   登录时间
 	 administrator                             3  断开         3:25  2015/8/5 12:02
 	 administrator                             4  断开           29  2015/8/5 14:28
 	 administrator                             5  断开         3:24  2015/8/4 14:44
    >administrator         rdp-tcp#0           6  运行中          .  2015/8/5 14:50

#2. 将文件夹挂载为盘符
[In windows, how to mount folder as a drive](http://serverfault.com/questions/24400/in-windows-how-to-mount-folder-as-a-drive)	

	subst m: c:\foo

#3. 设置环境变量
set path=%path%;C:\Windows\System32

#4. bat文件
调用方式"call test.bat zsy \\192.168.104.27\zsy Aa123!"，%1 %2 %3代表命令行相应的参数。

	@echo off
	set path=%path%;C:\Windows\System32
	net use P: /del /y
	net use P: /user:%1 %2 %3