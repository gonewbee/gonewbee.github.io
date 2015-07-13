---
layout: post
title:  "gdb调试应用"
date:   2015-07-13 19:40:13
categories: linux
sid:    gdb_manual
---

已xfreerdp为例：gdb client/X11/xfreerdp

#1. 设置断点

	(gdb) b XXX/XX.c:45 #在文件的第45行加断点
	(gdb) info break #查看断点信息

#2. 运行
	
	(gdb) r	//启动
	(gdb) r /v:192.168.1.74 /u:administrator /p:Aa123! /app:"||calc"	//带参数启动
	(gdb) n	//单步
	(gdb) s //单步，进入函数	

#3. 打印参数

	(gdb) p argc	//打印argc

#4. watch观察内存地址
流程：设置断点，run，到断点后设置watch，在continue

	//观察内存地址
	(gdb) p xfc->railWindows->numOfElements 
	$1 = 0
	(gdb) p &xfc->railWindows->numOfElements 
	$2 = (int *) 0x7fffe807dfa4
	(gdb) watch *(int *) 0x7fffe807dfa4
	Hardware watchpoint 2: *(int *) 0x7fffe807dfa4
	(gdb) c
	Continuing.
	Hardware watchpoint 2: *(int *) 0x7fffe807dfa4
	
	Old value = 0
	New value = 1
	HashTable_Add (table=0x7fffe807df70, key=0x10052, value=0x7fffe80b77f0)
	    at /home/zsy/Workspace/down/FreeRDP/winpr/libwinpr/utils/collections/HashTable.c:267
	267				if (table->upperRehashThreshold > table->idealRatio)
	(gdb) c

#5. call函数
强制调用销毁窗口函数，在init window时打印appWindow的地址，在FocusIn时加断点b client/X11/xf_event.c:1044

	(gdb) b client/X11/xf_event.c:1044
	(gdb) r /v:192.168.1.74 /u:administrator /p:Aa123! /app:"||WINWORD"
	(gdb) call xf_DestroyWindow((xfContext *) 0x60f160, (xfAppWindow *)0x7fffe80a19d0)
	(gdb) call XFlush(((xfContext *) 0x60f160)->display)

	
