---
layout: post
title:  "概率分布入门"
date:   2015-08-25 20:34:13
categories: python
sid:    probability_distribution_start
---

参考：[如何在Python中实现这五类强大的概率分布](http://python.jobbole.com/81321/)
使用[scipy.stats](http://docs.scipy.org/doc/scipy/reference/stats.html)绘制概率分布

# 1. 二项分布
二项分布（binomial distribution）有两个特点：
	
+ 各次试验相互独立
+ 每次试验得到一种结果的概率不变

二项分布有两个参数，一个是试验次数n，一个是每次试验成功的概率p，用符号表示B(n,p)或Bin(n,p)。例如：掷硬币，正面向上概率0.5，掷10次硬币，则正面向上次数的概率分布为[binomial.py](/files/binomial.py)：

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

# 2. 泊松分布
泊松分布（Poisson distribution），参考[泊松分布与美国枪击案](http://www.ruanyifeng.com/blog/2013/01/poisson_distribution.html)。如果平均值为2，则泊松分布[poisson.py](/files/poisson.py)：	

```python
#coding=utf-8
from scipy.stats import poisson
import numpy as np
import matplotlib.pyplot as plt

rate = 2 # 平均值为2
rv = poisson(rate) # 计算泊松分布
print(rv.pmf(0)) # 发生0次的概率

# 打印发生0-10次的概率列表
k = np.arange(0, 10)
print(rv.pmf(k))

# 使用matplotlib绘制出概率分布
plt.plot(k, rv.pmf(k), 'o-')
plt.title('Piosson: rate=%d' % (rate), fontsize=15)
plt.xlabel('Number of occur')
plt.ylabel('Probability of occur', fontsize=15)
plt.show()
```
执行python poisson.py输出：

```sh
0.135335283237
[  1.35335283e-01   2.70670566e-01   2.70670566e-01   1.80447044e-01
   9.02235222e-02   3.60894089e-02   1.20298030e-02   3.43708656e-03
   8.59271640e-04   1.90949253e-04]
```
![泊松分布](/images/poisson-distribution.png)

# 3. 超几何分布
超几何分布（hypergeometric distribution），是一种不放回抽样。

假如有500个产品，其中有5个次品，随机抽取20个，其中有两个次品的概率是多少[hypergeometric.py](/files/hypergeometric.py)。

```python
#coding=utf-8
from scipy.stats import hypergeom
import numpy as np
import matplotlib.pyplot as plt

# 500个产品包含5个次品，抽20个出来
[M, n, N] = [500, 5, 20]
rv = hypergeom(M, n, N) # 计算超几何分布
print(rv.pmf(2)) # 其中有两个次品的概率

# 抽出0-5个次品的概率
k = np.arange(0, n+1)
print(rv.pmf(k))

plt.plot(k, rv.pmf(k), 'o-')
plt.title('Hypergeom: total=%d total_bad=%d total_get=%d' % (M, n, N), fontsize=15)
plt.xlabel('Number of bad get')
plt.ylabel('Probability of get', fontsize=15)
plt.show()
```
![正态分布](/images/hypergeometric-distribution.png)

# 小结
如果将上例中的抽取改为抽一个放回后继续抽，那就是“放回式抽样”，对应的是二项分布。“不放回抽样”对应的是超几何分布。
