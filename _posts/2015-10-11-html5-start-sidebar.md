---
layout: post
title:  "html5学习之侧边栏实现"
date:   2015-10-11 13:43:54
categories: html5
sid:    html5_start_sidebar
---

打算学习一些html5的知识，暂时不使用jquery.js，计划做一个侧边栏，侧边栏可以隐藏，点击侧边栏中的菜单改变content中的内容。

	---------------------------------
		header
	---------------------------------
	|			|
	|sidebar 	|content
	|			|
	|			|

为适应移动设备，要进行响应式网站设计，主要两个点：
+ 在head中添加meta viewport
+ 在css中使用媒体查询，@media

## 1. 设置布局

```html
<div class="top"></div>
<div class="sidebar"></div>
<div class="content"></div>
```

使用absolute方式进行布局

```css
.top {
	position: absolute;
	left: 0; right: 0;
	height: 72px;
}
.sidebar {
	position: absolute;
	left: 0; top: 72px; bottom: 0;
	width: 178px;
}
.content {
    position: absolute;
    left:178px; top: 72px; right: 0; bottom: 0;
}
```

## 2. 隐藏/显示侧边栏
设置display为none或block可以控制元素的隐藏或显示。不使用js控制display只使用css实现的话可以使用label+input(checkbox)。

```html
<div class="top">
    <label id="sideBarControl" for="sideToggle">显示/隐藏菜单</label>
</div>
<input type="checkbox" id="sideToggle">
<div class="sidebar">
    <p>菜单内容</p>
</div>
<div class="content">
</div>
```

点击#sideBarControl相当于点击#sideToggle，可以根据#sideToggle:checked控制display。

```css
#sideToggle {
    display: none;
}
.sidebar {
    display: none;
}
.content {
    position: absolute;
    left:0; top: 72px; right: 0; bottom: 0;
}
#sideToggle:checked + .sidebar{display: block}
#sideToggle:checked ~ .content{left: 178px}
```

## 3. 添加菜单内容
使用ul li列表显示菜单内容。

```html
<div class="sidebar">
    <p>菜单内容</p>
    <ul class="nav">
        <li><a id="_1" href="#">Menu1</a> </li>
        <li><a id="_2" href="#">Menu2</a> </li>
        <li><a id="_3" href="#">Menu3</a> </li>
    </ul>
</div>
```

取消li前的点，为li添加边框，取消标签a的下划线，防止相邻的边框重叠使用:last-child进行设置

```css
.nav {
    list-style: none;
    position: absolute;
    left: 0;right: 0;
    padding: 0;
}
.nav a:link{color: #000}
.nav a:visited {color: #000}
.nav a:hover {
    color: #aaaaaa;
}
.nav li {
    border: solid 1px;
    padding: 5px 0 5px 0;
    border-bottom-width: 0px;
}
/*选择最后一个元素*/
.nav li:last-child {border-bottom-width: 1px}
.nav a {
    text-decoration: none;
}
```

## 4. 为菜单列表添加事件
不使用jquery的话，可以使用document.querySelectorAll选择元素，使用addEventListener添加事件。

```js
var items = document.querySelectorAll(".nav li");
//可以使用[].forEach.call进行遍历
[].forEach.call(items, function (item) {
	//添加click事件
    item.addEventListener("click", function() {
        var content = document.querySelector(".content");
        content.innerHTML = this.textContent;
    });
});
```

## 5. 设置active菜单
为被点击的菜单的class添加active项，使用this.parentNode.children可以获得所有兄弟元素。

```js
var items = document.querySelectorAll(".nav li");
// 可以使用Array.prototype.forEach.call进行遍历
[].forEach.call(items, function (item) {
//  添加click事件
    item.addEventListener("click", function() {
// 		遍历所有兄弟节点this.parentNode.children
        Array.prototype.forEach.call(this.parentNode.children, function (child) {
//          删除元素的某个class
            child.classList.remove("active");
        })
        this.classList.add("active");
        var content = document.querySelector(".content");
        content.innerHTML = this.textContent;
    });
});
```

修改active菜单的背景

```css
li.active {
    background-color: #f8f8f8;
    border-right-width: 0px;
}
```

## 6. 设置默认选中菜单
可以通过模拟鼠标点击设置默认的选择菜单

```js
document.querySelector("#_1").click(); // 模拟鼠标点击
```

## 7. 设置viewport
在head中添加如下代码：

```html
<meta name="viewport" content="width=device-width,user-scalable=no" />
```

## 8. 使用媒体查询

```css
@media only screen and (min-width: 992px) {
  .top {
    height: 72px; }

  .sidebar {
    top: 72px;
    width: 178px; }

  .content {
    top: 72px; }

  #sideToggle:checked ~ .content {
    left: 178px; } }
@media only screen and (max-width: 991px) {
  .top {
    height: 10%; }

  .sidebar {
    top: 10%;
    width: 30%; }

  .content {
    top: 10%; }

  #sideToggle:checked ~ .content {
    left: 30%; } }
```