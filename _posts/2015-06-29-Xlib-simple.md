---
layout: post
title:  "Xlib编程简单实例"
date:   2015-06-29 19:23:20
categories: linux
sid:    Xlib_simple
---
#1. 使用流程
[使用示例](/files/simple_event.c)

##1.1 XOpenDisplay
首先调用XOpenDisplay

	Display *dsp = XOpenDisplay(NULL);

##1.2 创建窗口
	XCreateWindow
创建好的Window需要XMapWindow和XFlush才能显示出来。