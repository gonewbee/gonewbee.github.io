---
layout: post
title:  "Windows下使用docker搭建nodejs的学习环境"
date:   2015-09-24 21:13:24
categories: docker
sid:    windows_docker_nodejs_start
---

打算在windows下编辑js文件，然后在docker中运行测试，使用-v将本机目录映射到docker容器中。

# 文件位置
通过ssh连接上docker虚拟机后，查看可得虚拟中有/c/Users/<用户名>目录，这里的内容是windows下的内容。

# 启动
+ 第一次启动

```sh
$ docker run -it -v /c/Users/zsy/Workspace:/Workspace -w /Workspace --name=nodeTest node bash
```

将/c/Users/<用户名>/Workspace下的内容挂到了/Workspace，可以进行测试了。

+ 以后再启动

```sh
$ docker start -i nodeTest
```
