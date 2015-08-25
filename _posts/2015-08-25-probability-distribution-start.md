---
layout: post
title:  "概率分布入门"
date:   2015-08-25 20:34:13
categories: python
sid:    probability_distribution_start
---

参考：[如何在Python中实现这五类强大的概率分布](http://python.jobbole.com/81321/)
使用[scipy.stats](http://docs.scipy.org/doc/scipy/reference/stats.html)绘制概率分布

#1. 二项分布
二项分布（binomial distribution）有两个特点：	
+ 各次试验相互独立
+ 每次试验得到一种结果的概率不变

二项分布有两个参数，一个是试验次数n，一个是每次试验成功的概率p，用符号表示B(n,p)或Bin(n,p)。例如：掷硬币，正面向上概率0.5，掷10次硬币，则正面向上次数的概率分布为：

```python
# coding=utf-8
from scipy.stats import binom
import numpy as np
import matplotlib.pyplot as plt

n, p = 10, 0.5 # 进行10次试验，每次成功概率0.5
rv = binom(n, p)
# pmf:Probability mass function, 质量函数
print(rv.pmf(0)) # 表示成功0次的概率
k = np.arange(0, n+1)
print(rv.pmf(k)) # k是一个数组，打印出成功对应次数的概率

# 使用matplotlib绘制出概率分布
plt.plot(k, rv.pmf(k), 'o-')
plt.title('Binomial: n=%i, p=%.2f' % (n,p), fontsize=15)
plt.xlabel('Number of successes')
plt.ylabel('Probability of successes', fontsize=15)
plt.show()
```
执行python binomial.py输出：
```sh
0.0009765625
[ 0.00097656  0.00976563  0.04394531  0.1171875   0.20507813  0.24609375
  0.20507813  0.1171875   0.04394531  0.00976563  0.00097656]
```
![二项分布](/images/binomial-distribution.png)
