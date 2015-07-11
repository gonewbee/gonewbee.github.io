---
layout: post
title:  "Xlib编程简单实例"
date:   2015-06-29 19:23:20
categories: linux
sid:    Xlib_simple
---
[EWMH](http://standards.freedesktop.org/wm-spec/wm-spec-latest.html)

#1. 使用流程
[使用示例](/files/simple_event.c)

##1.1 XOpenDisplay
首先调用XOpenDisplay

	Display *dsp = XOpenDisplay(NULL);

##1.2 创建窗口
	XCreateWindow
创建好的Window需要XMapWindow和XFlush才能显示出来。

##1.3 设置事件
设置事件

	XSelectInput(dsp, window, ButtonPressMask | ButtonReleaseMask);
获取事件

	XEvent event;
	XNextEvent(dsp, &event); #通过event.type判断事件类型

##1.4 手动发送事件
使用XSendEvent，向_NET_WM_MOVERESIZE的Atom发送事件，实现拖动窗口的功能，注意调用XUngrabPointer(cxt->display, CurrentTime);	
