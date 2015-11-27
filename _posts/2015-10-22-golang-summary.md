---
layout: post
title:  "golang学习汇总"
date:   2015-10-22 20:31:18
categories: summary
sid:    golang_summary
---

go语法格式：
+ 结尾不需要';'
+ 条件语句如for、if后不需要':'
+ 没有while，可使用for代替
+ switch时不需要break，一个case可使用多个表达式
+ for、if、while、switch的函数体要使用"{}"括起来

## 变量

### 声明类型
	var a string = "initial"
	var e int
	e = 1
一次声明多个

	var b, c int = 1, 2

### 自动类型
	var d = true
最简单写法

	f := "short"
	b, c := 1, 2

### 全局变量
可使用var tmp = "global"定义，不能使用tmp := "global"

## 常量
	const s string = "constant"

## 类型转换

### int与[]byte
网络字节序是大端模式
+ int转[]byte，大端模式可使用binary.BigEndian.PutUint16

	data := make([]byte, 16)
	var x uint16 = 0x1234
	var y uint32 = 0x12345678
	binary.BigEndian.PutUint16(data[1:], x)
	binary.BigEndian.PutUint32(data[3:], y)
+ []byte转int

	a := binary.BigEndian.Uint16(data[1:])
	b := binary.BigEndian.Uint32(data[3:])

### string转int
使用strconv包

	s := "ff"
	num, err := strconv.ParseInt(s, 16, 64) # 16进制，int64

### int转string
可使用fmt.Sprintf得到格式化字符串

	s := fmt.Sprintf("%04x%04x%04x%04x", x, y, w, h)
	log.Println(s)

### []byte和string
+ string转[]byte

	s := "Hello World!"
	data = []byte(s)

+ []byte转string, [What is the best way to convert byte array to string?](http://stackoverflow.com/questions/14230145/what-is-the-best-way-to-convert-byte-array-to-string)

	s := string(byteArray)
	// or
	s := string(byteArray[:n])

	

