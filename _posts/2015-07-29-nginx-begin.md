---
layout: post
title:  "nginx入门"
date:   2015-07-24 20:24:47
categories: tools
sid:    nginx_begin
---

#1. 命令行
+ 启动：nginx;windows下启动nginx: start nginx
+ -c指定启动配置文件：nginx -c /XXX/XXX/nginx.conf;windows下启动start nginx -c D:\workspace\python27\MyGuess\nginx.conf
+ 停止：nginx -s stop 或 nginx -s quit
+ 重启：nginx -s reload

#2. 配置

##2.1 文件路径

	location ~ \.(mp3)$ {
		root D://BaiduYunDownload;
	}

##2.2 重定向

	location / {
        proxy_pass http://127.0.0.1:5000/;
    }

