---
layout: post
title:  "python学习"
date:   2015-06-21 11:30:20
categories: python
sid:    python_learn
---
## 1.1 转换java的System.currentTimeMillis() ##
将java的System.currentTimeMillis()使用Python打印出时间，由于得到的是milliseconds，要先除以1000.0
使用time

	>>> import time
	>>> time.localtime(1433147713826/1000.0)
	time.struct_time(tm_year=2015, tm_mon=6, tm_mday=1, tm_hour=1, tm_min=35, tm_sec=13, tm_wday=0, tm_yday=152, tm_isdst=1)
使用datetime

	>>> import datetime
	>>> datetime.datetime.fromtimestamp(1433147713826/1000.0)
	datetime.datetime(2015, 6, 1, 1, 35, 13, 826000)

## 1.2 ipython ##
启动：ipython notebook --pylab=inline

	