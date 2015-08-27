---
layout: post
title:  "使用Dockerfile创建image"
date:   2015-08-27 21:13:52
categories: docker
sid:    dockerfile_use
---

# 自定义镜像
+ 安装基础镜像
	docker pull ubuntu:14.04
+ 编写测试应用hello
+ 编写Dockerfile



## 编写测试文件
编写简单的web服务，hello.go：
```go
package main

import "log"
import "net/http"
import "io"

func HelloServer(w http.ResponseWriter, req *http.Request) {
	log.Println("HelloServer enter")
	io.WriteString(w, "Hello, World!. Run in Docker \n")
}

func main() {
	port := "5000"
	http.HandleFunc("/", HelloServer)
	log.Println("Server started: http://localhost:" + port)
	log.Fatal(http.ListenAndServe(":"+port, nil))
}

```
编译go build hello.go，生成hello

## 编写Dockerfile
参考[Best practices for writing Dockerfiles](https://docs.docker.com/articles/dockerfile_best-practices/)

```script
# 自定义的镜像基于ubuntu:14.04
FROM ubuntu:14.04

# 设置环境变量
ENV DIRPATH /root

# 复制编译后的文件到制定目录，/root/hello
COPY hello $DIRPATH/hello

# 端口
EXPOSE 5000

# 制定工作目录
WORKDIR $DIRPATH

# 运行程序
CMD ./hello
```

## 目录结构

	.
	└── mydockerbuild
	    ├── Dockerfile
	    ├── hello
	    └── hello.go


## 生成镜像
在mydockerbuild目录执行如下命令，生成镜像docker-hello，可通过docker images指令查看到。
```sh
docker build -t docker-hello .
```
## 测试
docker运行可参考[Linking containers together](https://docs.docker.com/userguide/dockerlinks/)

+ 运行镜像，-P 自动映射端口，可通过docker ps查看映射
```sh
docker run -d -P docker-hello
```
+ 查看端口，得知映射端口为32768
```sh
$ docker ps
CONTAINER ID        IMAGE               COMMAND                CREATED             STATUS              PORTS                     NAMES
edf87fa43c2b        docker-hello        "/bin/sh -c ./hello"   4 seconds ago       Up 2 seconds        0.0.0.0:32768->5000/tcp   nostalgic_poincare
```
+ 测试结果
```sh
$ curl http://localhost:32768
Hello, World!. Run in Docker 
```
+ 指定端口和名称运行，-p 指定端口映射，--name 指定container 的名称
```sh
$ docker run -d -p 80:5000 --name hello_test docker-hello
```

# 镜像迁移
参考[docker容器跨服务器的迁移方式export和save](http://xiaorui.cc/2014/09/18/docker%E5%AE%B9%E5%99%A8%E8%B7%A8%E6%9C%8D%E5%8A%A1%E5%99%A8%E7%9A%84%E8%BF%81%E7%A7%BB%E6%96%B9%E5%BC%8Fexport%E5%92%8Csave/)

+ save保存镜像：docker save docker-hello > ~/out/docker-hello.tar
+ load导入镜像：docker load < docker-hello.tar
+ 测试，在windows下使用boot2docker测试，将docker-hello.tar复制到C:\Users\zsy下
```sh
$ docker.exe load < docker-hello.tar
$ docker.exe run -d -p 80:5000 docker-hello
```
通过boot2docker.exe ip 获取ip地址，在浏览器中测试。



