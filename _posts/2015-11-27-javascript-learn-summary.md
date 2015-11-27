---
layout: post
title:  "javascript学习总结"
date:   2015-11-27 19:32:46
categories: summary
sid:    javascript_learn_summary
---

## string

### string判断startsWith
[How to check if a string “StartsWith” another string?](http://stackoverflow.com/questions/646628/how-to-check-if-a-string-startswith-another-string)

	function stringStartsWith (string, prefix) {
	    return string.slice(0, prefix.length) == prefix;
	}

## DOM操作

### 如何查找DOM
[document.querySelector](https://developer.mozilla.org/en-US/docs/Web/API/Document/querySelector)得到element对象，[document.querySelectorAll](https://developer.mozilla.org/en-US/docs/Web/API/Document/querySelectorAll)得到的时列表，可通过Array.prototype.forEach.call的方式遍历，[测试例子](https://github.com/zhangshy/myTest/commit/34708dafe607939bc1e878e20e91c92575ceeb6e#diff-24cd804fb48430e7788b3d0b8c722833)。

### 操作class
对Element.classList进行add、remove。

	var loading = document.querySelector('.loading');
	loading.classList.add('showCentor');
	loading.classList.remove('showCentor');

### 添加事件
通过addEventListener添加事件，使用preventDefault阻止默认操作，[例子](https://github.com/gonewbee/webRDP/commit/3b4dc0977b103c17ee8c893f1c6c8084916b81d8#diff-eacf331f0ffc35d4b482f1d15a887d3b)

	  var loginform = document.querySelector("#loginForm");
	  loginform.addEventListener("submit", function(evt) {
	    evt.preventDefault();
	    console.log("onsubmit");
	    var data = {};
	    data.type = "login";
	    data.ip = this["ip"].value;
	    data.user = this["user"].value;
	    data.passwd = this["passwd"].value;
	    console.log(data);
	    websocket.send(JSON.stringify(data));
	  }, false)
