---
layout: post
title:  "编程语言总结一"
date:   2015-11-22 15:13:27
categories: summary
sid:    language_summary1
---

golang学习示例[gobyexample](https://gobyexample.com/)

## 变量

### golang

	var s string // 完整声明
	var a int = 3 // 初始化
	b := 4 // 可使用:=简化，编译的时候会自动推导类型

### javascript

	var s = "javascript"; // 加var是局部变量
	a = 3; // 不使用var的变量是全局变量

### python
	
	s = "python"


## 列表

### golang
go中使用slice，如：[]byte。

	s := make([]string, 3)
	s[0] = "a" // 赋值
	s = append(s, "d") // 增加数据
	t := []string{"g", "h", "i"} // 声明时候直接赋值

### javascript
javascript中使用Array，[参考](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array)。避免使用new Array()，使用[]。

	var fruits = ["Apple", "Banana"];
	fruits.push("Orange");

### python
[参考](https://docs.python.org/2/tutorial/datastructures.html)

	stack = [3, 4, 5]
	squares = []
	squares.append(333)

## map或dict

### golang
go中使用map

	m := make(map[string]int)
	m["k1"] = 7
	m["k2"] = 13
	v1 := m["k1"]
	delete(m, "k2")
	n := map[string]int{"foo": 1, "bar": 2}

### javascript
javascript可以使用object做map使用。[参考](http://stackoverflow.com/questions/6298169/how-to-create-a-map-object-in-javascript)

	var a = {};
	a["key1"] = "value1";
	a["key2"] = "value2";
	if ("key1" in a) {
	   // something
	} else {
	   // something else 
	}

删除操作[How to remove a property from a JavaScript object](http://stackoverflow.com/questions/208105/how-to-remove-a-property-from-a-javascript-object)

	var myJSONObject = {"ircEvent": "PRIVMSG", "method": "newURI", "regex": "^http://.*"};
	delete myJSONObject.regex;
	// or,
	delete myJSONObject['regex'];
	// or,
	var prop = "regex";
	delete myJSONObject[prop];

### python
python中是[dict](https://docs.python.org/2/library/stdtypes.html#dict)

	dishes = {'eggs': 2, 'sausage': 1, 'bacon': 1, 'spam': 500}
	del dishes['eggs']

## json

### javascript
Json字符串转js对象使用JSON.parse(str);

	var str = '{"Type":"DeleteWin","WinId":"46137581"}';
	var data = JSON.parse(str);
	console.log(data.Type); //data["Type"]

js对象转Json字符串使用JSON.stringify(data)

	var data = {};
	data.Type = "DeleteWin";
	data["WinId"] = "46137581";
	var str = JSON.stringify(data);

### golang
使用"encoding/json"包，在struct中添加omitempty，表明此项可以为空，json.Unmarshal解析Json数据，json.Marshal生成Json数据。


## javascript对象操作

	var data = {};
	// 添加
	data.Type = "type1";
	data["Name"] = "name1";
	// 判断是否存在
	if ("Type" in data) {
		console.log("Type exist!");
	}
	// 删除
	delete icons["Type"];
	// 遍历
	for (var key in data) {
		console.log(data.key); // console.log(data[key]);
	}