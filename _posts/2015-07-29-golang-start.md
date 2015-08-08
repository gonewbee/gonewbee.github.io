---
layout: post
title:  "golang环境搭建"
date:   2015-08-01 12:24:23
categories: golang
sid:    golang_start
---

[go语言示例](https://gobyexample.com/)

#1 Ubuntu搭建go语言环境

##1.1 安装

下载安装包go1.4.2.linux-amd64.tar.gz，解压

	sudo tar -C /usr/local -xzf go1.4.2.linux-amd64.tar.gz

解压后设置环境变量，在.bashrc中添加：

	export PATH=$PATH:/usr/local/go/bin

##1.2 测试
编写hello world示例

	#hello.go
	package main
	
	import "fmt"
	
	func main() {
	    fmt.Printf("hello, world!\n")
	}
运行hello.go

	$ go run hello.go 
	hello, world!
编译：

	$ go build hello.go
	$ ./hello 
	hello, world!

#2 变量

##2.1 声明
使用var，变量类型在变量名后面，

+ var a string = "initial" //string类型变量a
+ var b, c int = 1, 2	// int 类型变量b，c

可以省略变量类型：var d = true

使用":="做简化声明

	f := "short"
    fmt.Println(f)

##2.2 数组
+ var a [5]int
+ var twoD [2][3]int
+ b := [5]int{1, 2, 3, 4, 5}

#2. windows #
安装windows后需要环境变量GOPATH，在环境变量中添加如GOPATH:D:\test\go

#3. 编译
[How to Write Go Code](http://godoc.golangtc.com/doc/code.html)

函数首字母大写，才能被别的包调用。

