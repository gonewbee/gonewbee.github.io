---
layout: post
title:  "python数据类型"
date:   2015-07-24 21:03:10
categories: python
sid:    python_types
---
参考：[Data Structures](https://docs.python.org/2/tutorial/datastructures.html)

#1 list

#1.1 申明list
申明一个空的list有两种方式：

	1. mylist = list()
	2. mylist = []

#1.2 操作
L = [i*i for i in range(4)] #[0, 1, 4, 9]

+ L.append(25) #追加元素，[0, 1, 4, 9, 25]
+ L.insert(4, 16) #在指定位置插入元素，[0, 1, 4, 9, 16, 25]
+ L.extend([36, 49]) #追加list，即合并到L上, [0, 1, 4, 9, 16, 25, 36, 49]
+ L.remove(4) #删除指定元素，[0, 1, 9, 16, 25, 36, 49]
+ L.pop(2) #返回第二个元素，并删除。返回9，[0, 1, 16, 25, 36, 49]。如果不加参数，返回最后一个并删除。
+ L.index(16) #查找元素在列表中的位置
+ L.count(25) #计算元素在列表中的数目
+ L.sort() #排序
+ L.reverse() #倒序
+ del L[1] #删除指定下标的元素，[0, 16, 25, 36, 49]
+ del L[1:3]  #删除指定下标范围的元素

#2 dict
参考：[dict](https://docs.python.org/2/library/stdtypes.html#dict)

##2.1 申明dict
申明一个空的dict的两种方法：

	1. new_dict = dict()
	2. new_dict = {}
初始化dict

	>>> a = dict(one=1, two=2, three=3)
	>>> b = {'one': 1, 'two': 2, 'three': 3}
	>>> c = dict(zip(['one', 'two', 'three'], [1, 2, 3]))
	>>> d = dict([('two', 2), ('one', 1), ('three', 3)])
	>>> e = dict({'three': 3, 'one': 1, 'two': 2})
	>>> a == b == c == d == e
	True

##2.2 操作
d = dict([('two', 2), ('one', 1), ('three', 3)])

+ len(d) #dict长度，3
+ d['two'] #取key对应的值，2
+ del d['two'] #删除key
+ d.get('two', -1) #-1，取key值
+ 'two' in d #判断key是否在dict中，False
+ d.has_key('two') #判断key是否存在，False
+ d.keys() #返回所有key，['three', 'one']
+ d.values() #返回所有数值，[3, 1]
+ d.items() #[('three', 3), ('one', 1)]
+ d.pop('one', -1) #返回并删除key，如果不存在返回default值
+ d.setdefault('two', 3) #如果key不存在，设置值为default并返回，如果key已经存在直接返回对应的value