---
layout: post
title:  "FreeRDP说明"
date:   2015-08-25 20:18:28
categories: linux
sid:    freerdp_summary
---

+ 代码：FreeRDP master分支
+ 参考：[MS-RDPBCGR]

# 1. 连接参数

## 1.1 GCC

+ 参考：2.2.1.3.2 Client Core Data (TS_UD_CS_CORE)
+ 代码：libfreerdp/core/gcc.c gcc_write_client_core_data

参数包括：

+ RDP版本：version信息并不能准确的反应正在使用的RDP版本，目前使用版本7。 

| 数值		| 含义	|
| :--------	| :---- |
| 0x00080001| RDP 4.0 clients	|
| 0x00080004| RDP 5.0, 5.1, 5.2, 6.0, 6.1, 7.0, 7.1, 8.0, and 8.1 clients|
| 0x00080005| RDP 10.0 clients|

+ 桌面宽、高和会话名称 
+ 连接速度：connectionType为6（CONNECTION_TYPE_LAN）
+ 将要使用的通道个数和名称：2.2.1.3.4 Client Network Data (TS_UD_CS_NET)，libfreerdp/core/gcc.c的gcc_write_client_network_data

# 2. 静态通道
参考：1.3.3 Static Virtual Channels

## 2.1 通道定义
以剪切板重定向功能为例，文件channels/cliprdr/client/cliprdr_main.c内实现cliprdr_VirtualChannelEntry，该函数应该是通道加载的入口。所有可支持的通道添加在文件channels/client/tables.c的CLIENT_VirtualChannelEntry_TABLE和CLIENT_STATIC_ADDIN_TABLE数组中。

## 2.2 启用通道
通过gdb查看调用流程。

查找通道

```sh
#0  freerdp_load_channel_addin_entry (pszName=0x7fffe8000950 "cliprdr", pszSubsystem=0x0, pszType=0x0, dwFlags=4096)
    at /home/zsy/Workspace/code/ubuntu14/FreeRDP/libfreerdp/common/addin.c:277
#1  0x00007ffff789e949 in freerdp_client_load_static_channel_addin (channels=0x6441c0, settings=0x614b10, name=0x7fffe8000950 "cliprdr", 
    data=0x7fffe8000910) at /home/zsy/Workspace/code/ubuntu14/FreeRDP/client/common/cmdline.c:2328
#2  0x00007ffff789ee2f in freerdp_client_load_addins (channels=0x6441c0, settings=0x614b10)
    at /home/zsy/Workspace/code/ubuntu14/FreeRDP/client/common/cmdline.c:2475
#3  0x00007ffff7b4e61f in xf_pre_connect (instance=0x60ee80) at /home/zsy/Workspace/code/ubuntu14/FreeRDP/client/X11/xf_client.c:995
#4  0x00007ffff5d2875e in freerdp_connect (instance=0x60ee80) at /home/zsy/Workspace/code/ubuntu14/FreeRDP/libfreerdp/core/freerdp.c:76
#5  0x00007ffff7b4ff10 in xf_client_thread (param=0x60ee80) at /home/zsy/Workspace/code/ubuntu14/FreeRDP/client/X11/xf_client.c:1530
#6  0x00007ffff760329b in thread_launcher (arg=0x652e20) at /home/zsy/Workspace/code/ubuntu14/FreeRDP/winpr/libwinpr/thread/thread.c:315
#7  0x00007ffff554b182 in start_thread (arg=0x7fffee44d700) at pthread_create.c:312
#8  0x00007ffff72b447d in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:111
```
通道启动：

```sh
(gdb) b channels/cliprdr/client/cliprdr_main.c:972
No source file named channels/cliprdr/client/cliprdr_main.c.
Make breakpoint pending on future shared library load? (y or [n]) y
Breakpoint 1 (channels/cliprdr/client/cliprdr_main.c:972) pending.
(gdb) r /v:192.168.102.12 /u:administrator /p:123456 /app:"||WINWORD" +clipboard
Starting program: /home/zsy/Workspace/code/ubuntu14/FreeRDP/client/X11/xfreerdp /v:192.168.102.12 /u:administrator /p:123456 /app:"||WINWORD" +clipboard
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
[New Thread 0x7fffee44d700 (LWP 9615)]
[Switching to Thread 0x7fffee44d700 (LWP 9615)]

Breakpoint 1, cliprdr_VirtualChannelEntry (pEntryPoints=0x7fffee44c7e0)
    at /home/zsy/Workspace/code/ubuntu14/FreeRDP/channels/cliprdr/client/cliprdr_main.c:972
972		cliprdr = (cliprdrPlugin*) calloc(1, sizeof(cliprdrPlugin));
(gdb) backtrace 
#0  cliprdr_VirtualChannelEntry (pEntryPoints=0x7fffee44c7e0)
    at /home/zsy/Workspace/code/ubuntu14/FreeRDP/channels/cliprdr/client/cliprdr_main.c:972
#1  0x00007ffff5d2bad6 in freerdp_channels_client_load (channels=0x6441c0, settings=0x614b10, 
    entry=0x7ffff78ba68e <cliprdr_VirtualChannelEntry>, data=0x7fffe8000910)
    at /home/zsy/Workspace/code/ubuntu14/FreeRDP/libfreerdp/core/client.c:735
#2  0x00007ffff789e8d4 in freerdp_client_load_static_channel_addin (channels=0x6441c0, settings=0x614b10, name=0x7fffe8000950 "cliprdr", 
    data=0x7fffe8000910) at /home/zsy/Workspace/code/ubuntu14/FreeRDP/client/common/cmdline.c:2332
#3  0x00007ffff789ed8a in freerdp_client_load_addins (channels=0x6441c0, settings=0x614b10)
    at /home/zsy/Workspace/code/ubuntu14/FreeRDP/client/common/cmdline.c:2475
#4  0x00007ffff7b4e61f in xf_pre_connect (instance=0x60ee80) at /home/zsy/Workspace/code/ubuntu14/FreeRDP/client/X11/xf_client.c:995
#5  0x00007ffff5d28709 in freerdp_connect (instance=0x60ee80) at /home/zsy/Workspace/code/ubuntu14/FreeRDP/libfreerdp/core/freerdp.c:76
#6  0x00007ffff7b4ff10 in xf_client_thread (param=0x60ee80) at /home/zsy/Workspace/code/ubuntu14/FreeRDP/client/X11/xf_client.c:1530
#7  0x00007ffff760329b in thread_launcher (arg=0x652e20) at /home/zsy/Workspace/code/ubuntu14/FreeRDP/winpr/libwinpr/thread/thread.c:315
#8  0x00007ffff554b182 in start_thread (arg=0x7fffee44d700) at pthread_create.c:312
#9  0x00007ffff72b447d in clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:111
```

# 3. rail参数
rdp的远程应用参数设置

+ 支持本地拖动 client/X11/xf_rail.c 

```c
	clientStatus.flags = RAIL_CLIENTSTATUS_ALLOWLOCALMOVESIZE;
``` 

# 4. usb重定向
安装依赖库

```sh
$ sudo apt-get install libusb-1.0-0-dev
$ sudo apt-get install libdbus-glib-1-dev
$ sudo apt-get install uuid-dev
```

cmake参数

```sh
cmake -DCMAKE_BUILD_TYPE=Debug -DWITH_SSE2=ON -DCHANNEL_URBDRC_CLIENT=ON .
```

# 5. 打印机重定向
cmake时添加-DWITH_CUPS=ON

```sh
cmake -DCMAKE_BUILD_TYPE=Debug -DWITH_SSE2=ON -DWITH_CUPS=ON .
```