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
