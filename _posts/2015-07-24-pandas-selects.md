---
layout: post
title:  "pandas数据选择说明"
date:   2015-07-24 20:24:47
categories: pandas
sid:    pandas_selects
---
pandas DataFrame的各种选择，[cookbook selection](http://pandas.pydata.org/pandas-docs/version/0.16.2/cookbook.html#selection)

	import pandas as pd
	import numpy as np
	data = {'AAA' : [4,5,6,7], 'BBB' : [10,20,30,40],'CCC' : [100,50,-30,-50]}
	df = pd.DataFrame(data=data,index=['la','lb','ld','ld'])

#1 选择行

##1.1 []行数方式
切片参数选择多行，python规则，不包含结尾行数。df[0:2]选择第0和第1行，不包行第2行，等效于df.iloc[0:2]

##1.2 iloc行数方式
+ df.iloc[0] : 第0行
+ df.iloc[1:3] : 切片选择符合python规则，包含开头的0不包含结尾的3，即选择的是第1和第2行。

##1.3 按行名称选择
df.index可获取行名称，使用len(df.index)可得到该DataFrame的行数。行名称分别为la,lb,lc,ld

+ df.loc['la'] : 取行名称为la的行
+ df.loc['la':'lc'] : 不是python的切片规则，也要包括结尾的'lc'，即取la、lb、lc这三行。

##1.4 ix方式
+ df.ix[0] 等价于df.iloc[0]
+ df.ix['la'] 等价于df.loc['la']
+ df.ix[0:2] 等价于df.iloc[0:2]
+ df.ix['la':'lc'] 等价于df.loc['la':'lc']

#2 选择列

##2.1 []方式
+ df['AAA'] : 选择单列
+ df[['AAA','BBB']] : 选择多行，AAA和BBB两行

##2.2 iloc列数方式
+ df.iloc[:,0] : 选择第0列
+ df.iloc[:,0:2] : 选择第0和第1列

##2.3 loc列名称选择
+ df.loc[:,'AAA'] : 选择单列
+ df.loc[:, ['AAA', 'BBB']] : 选择AAA和BBB两行

#3 loc按名称选择
+ df.loc['la', 'AAA'] : 选择的是单个元素
+ df.loc['la':'lc',['AAA','BBB']] : 选择的是一个3X2的矩阵

#4 iloc按位置选择
+ df.iloc[0,0] : 选择第0行第0列的元素
+ df.iloc[0:2,0:2] : 选择的是坐上角的2X2的矩阵元素

#5 注意
iloc中的切片slice是符合python规则的（包含开头不包含结尾），loc中的切片是非python规则的（包含开头和结尾）。
