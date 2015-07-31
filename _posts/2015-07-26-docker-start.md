---
layout: post
title:  "docker入门"
date:   2015-07-26 20:46:03
categories: docker
sid:    docker_start
---

#1. image

#1.1 查看image
docker images

#1.2 安装image
docker pull ubuntu:14.04	

docker run -it ubuntu:14.04 #启动ubuntu，并进入命令行模式

#2. Working with containers
+ docker ps - Lists containers
+ docker logs - Shows us the standard output of a container.
+ docker stop - Stops running containers.

运行一个web应用，先安装image：docker pull training/webapp

#2.1 run
	$ docker run -d -P training/webapp python app.py
-d是后台运行。

#2.2 查看
使用docker ps查看正在运行的container，如果要查看包括已经stopped的container添加-a参数。

	$ docker ps -l
	CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS                     NAMES
	3a8cfbd8897b        training/webapp     "python app.py"     6 minutes ago       Up 3 minutes        0.0.0.0:32768->5000/tcp   determined_hodgkin
使用boot2docker ip查看ip

	$ boot2docker.exe ip
	192.168.59.103
在浏览器中输入：http://192.168.59.103:32768/查看结果。

#2.3 查看log
使用docker logs查看log

	$ docker logs -f determined_hodgkin
	 * Running on http://0.0.0.0:5000/ (Press CTRL+C to quit)
	192.168.59.3 - - [27/Jul/2015 05:50:36] "GET / HTTP/1.1" 200 -
使用-f参数和tail -f功能类似，可以得到实时的更新。

#2.4 停止
docker stop停止container

	$ docker stop determined_hodgkin
	determined_hodgkin

#2.5 重启
docker start启动已经停止的container。还可以使用restart停止再启动一个正在运行的container

	$ docker start determined_hodgkin
	determined_hodgkin

#2.6 删除
docker rm删除一个停止的container

	$ docker stop determined_hodgkin
	determined_hodgkin
	$ docker rm determined_hodgkin
	determined_hodgkin

查看所有的container：$ docker.exe ps -a