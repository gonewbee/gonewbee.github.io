---
layout: post
title:  "Windows下使用MobaXterm ssh连接docker"
date:   2015-09-24 20:42:13
categories: docker
sid:    windows_docker_MobaXterm
---

# 启动docker虚拟机

+ 双击Docker Quickstart Terminal图标启动虚拟机。
+ 使用docker-machine ip指令查看虚拟机IP地址。

```sh
$ docker-machine.exe ip default
192.168.99.100
```

# ssh连接

+ 启动MobaXterm
+ 选择SeSSions--New session，点击SSH
+ Remote host填写上步查看到的IP（192.168.99.100）
+ 设置密钥：点击Advanced SSH settings，勾选Use private key，然后点击文件浏览选择文件，文件为：C:\Users\<用户名>\.docker\machine\machines\default\id_rsa，点击OK
+ 在login as中输入docker，ssh连接成功。