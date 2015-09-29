---
layout: post
title:  "xfreerdp窗口本地拖动功能"
date:   2015-08-17 20:17:12
categories: linux
sid:    xfreerdp_move
---

参考[MS-RDPERP]1.3.2.5 RAIL Local Move/Resize

1.	服务端检测到窗口拖动或缩放，服务端发送最大最小信息，freerdp接收函数channels/rail/client/rail_orders.c：rail_recv_server_minmaxinfo_order，然后服务端发送开始移动消息，freerdp接收函数channels/rail/client/rail_orders.c：rail_recv_server_localmovesize_order，处理函数对应的是client/X11/xf_rail.c：xf_rail_server_local_move_size--xf_StartLocalMoveSize，设置状态appWindow->local_move.state = LMS_STARTING;
2.	本地事件响应，client/X11/xf_event.c：xf_event_suppress_events，当local_move.state为LMS_STARTING时收到ConfigureNotify事件认为本地移动开始，设置appWindow->local_move.state = LMS_ACTIVE;
3.	使用本地窗口管理器处理鼠标、按键事件，不向服务端发送，确保移动在本地发生。
4.	当本地移动结束时客户端向服务端发送一个mouse button-up，client/X11/xf_rail.c：xf_rail_end_local_move，设置appWindow->local_move.state = LMS_TERMINATING;。然后客户端向服务端发送本地窗口移动channels/rail/client/rail_main.c：rail_client_window_move，通知服务端窗口的位置。
5.	服务端检测到移动结束时，向客户端发送移动停止事件，client/X11/xf_window.c：xf_EndLocalMoveSize，设置appWindow->local_move.state = LMS_NOT_ACTIVE;，客户端如果需要会调整窗口位置。