---
layout: post
title:  "wireshark使用"
date:   2015-07-23 20:13:21
categories: tools
sid:    wireshark_filter
---
关于Wireshark "The NPF driver isn’t running……"解决办法:	

在开始--搜索cmd--以管理员权限运行--输入net start npf 启动服务，net stop npf可关闭服务。
#1 wireshark过滤
+ 目的ip：ip.dst==192.168.1.74
+ tcp端口：tcp.port==3389
+ tcp包内容包含：tcp contains 10:b6	
+ 组合过滤：tcp.port==3389 && tcp contains 10:00