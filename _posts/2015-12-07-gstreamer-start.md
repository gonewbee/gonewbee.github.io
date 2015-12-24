---
layout: post
title:  "gstreamer学习"
date:   2015-12-07 20:38:42
categories: linux
sid:    gstreamer_start
---

## gst-launch

### 播放MP4
安装：

```sh
sudo apt-get install gstreamer1.0-tools gstreamer1.0-alsa gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav
```
播放：

```sh
gst-launch-1.0 -v playbin uri=file:///home/zsy/Downloads/test.mp4
```

### 播放H264文件
如果不使用playbin可以使用decodebin和videoconvert播放H264文件
```sh
$ gst-launch-1.0 filesrc location=`pwd`/test.h264 ! decodebin name=videodecoder ! videoconvert ! autovideosink
```

## gst-inspect
用来查看插件信息如：gst-inspect-1.0 appsrc

## 基础

### Elements
element时GStreamer中最重要的对象，每个element都可以有一个特定的方法，如从文件中读取数据、解码数据、将数据放到声卡中等。把element串联起来创建一个做特定事情的pipeline。

### Pads
Pads时element连接其它elements的输入和输出，Pads可以看做是element的用于连接其它element的插头。一个pad可以限制通过它的数据类型。

![simple-player](http://gstreamer.freedesktop.org/data/doc/gstreamer/head/manual/html/images/simple-player.png)

![communication](http://gstreamer.freedesktop.org/data/doc/gstreamer/head/manual/html/images/communication.png)