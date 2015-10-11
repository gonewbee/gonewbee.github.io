---
layout: post
title:  "全栈工程师学习--react初学"
date:   2015-09-07 21:36:10
categories: 前端
sid:    full_stack_react
---

在react中最主要的是将界面分割成component

## 界面分割成组件
将界面分割成几个单独的组件，这里将界面分割成了5个组件。

	------------- NetFile
	 - SideBar	- MenuResponse
					- BrowseFile
					- UploadFile

其中NetFile是整个大的框；SideBar是左侧的侧边框，打算在里面放一些按键；MenuResponse是对按键的响应，初步设计有浏览文件目录和上传文件这两个功能，在MenuResponse中显示BrowseFile或UploadFile。

### React.js中onClick传递参数
使用 **.bind** 去传递参数

```js
<input className="btn btn-default" type="button" value="文件浏览" onClick={this.handleInputClick.bind(this, "browse file")}
```

### 数据传递

+ this.props
+ this.state 主要用于界面交互
