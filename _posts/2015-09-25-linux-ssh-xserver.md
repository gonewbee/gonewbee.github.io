---
layout: post
title:  "ssh连接Linux后远程xserver设置"
date:   2015-09-25 19:46:07
categories: linux
sid:    linux_ssh_xserver
---

ssh登录到linux系统后，可以设置图形的显示屏幕，查看环境变量DISPLAY

# 在被登录电脑上显示

```sh
$ export DISPLAY=:0
```

# 在登录电脑上显示
ssh连接时加参数-X

```sh
$ ssh -X user@hostname
```