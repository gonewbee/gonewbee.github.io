---
layout: post
title:  "windows挂载samba共享"
date:   2015-08-04 19:48:31
categories: windows
sid:    windows_samba
---

#1. windows挂载samba
[参考](http://rainbird.blog.51cto.com/211214/197794/)

##1.1 net
+ 挂载到P盘。net use P: \\192.168.163.134\share
+ 删除挂载。net use P: /del /y
+ 使用密码挂载：net use P: /user:zsy \\192.168.104.27\share\zsy Aa123!

##1.2 pushd/popd
通过net use指令连接samba共享文件后如果不map到指定盘，可以通过pushd创建临时盘符，使用结束后通过popd删除临时盘符。[How do I connect to a network share via the Windows Command Prompt?](http://superuser.com/questions/52220/how-do-i-connect-to-a-network-share-via-the-windows-command-prompt)

	net use \\192.168.104.27\share\zsy
	pushd \\192.168.104.27\share\zsy #创建临时盘
	popd	#删除临时盘

##1.3 subst
+ subst P: \\192.168.104.27\share\yugl #产生盘符P
+ subst P: /D #删除

##1.4 mklink
[Mount Remote CIFS/SMB Share as a Folder not a Drive Letter](http://serverfault.com/questions/105633/mount-remote-cifs-smb-share-as-a-folder-not-a-drive-letter)。创建一个快捷方式，而不是挂载为盘符

	mklink /d  C:\Folder\ShareName \\Server\ShareName\Directory

##1.5 freerdp
在freerdp连接时通过cmd命令挂载samba共享

	xfreerdp /v:192.168.102.13 /u:zsy /p:Aa123! /app:"||cmd" /app-cmd:"/C C:\\windows\\system32\\net use P: /user:zsy \\\\192.168.104.27\\zsy Aa123!"

#2. veracrypt磁盘加密软件
C:\Users\zsy>"D:\Program Files\VeraCrypt\VeraCrypt.exe" /q /v \\192.168.163.134\
share\MyVolume /p 745123

#3. 虚拟磁盘VHD
[参考](https://technet.microsoft.com/en-us/library/gg318052(v=ws.10).aspx)

新建脚本文件D:\lqbz\test.txt，输入一下内容，执行diskpart /s D:\lqbz\test.txt。会在D:\lqbz生成一个200M的vhd文件，格式化并挂载到m盘。

	create vdisk file=D:\lqbz\test.vhd maximum=200
	attach vdisk 
	create partition primary 
	format fs=ntfs label="test volume" quick
	assign letter=m

对于已经存在的vhd文件，可以使用：

	select vdisk file=D:\lqbz\test.vhd
	attach vdisk
	exit

可以在“开始”--搜索中输入“diskmgmt.msc” 进行磁盘管理。

#4. bitlocker
manage-bde -lock M:
