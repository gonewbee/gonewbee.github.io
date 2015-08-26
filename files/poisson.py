#coding=utf-8
from scipy.stats import poisson
import numpy as np
import matplotlib.pyplot as plt

rate = 2 # 平均值为2
rv = poisson(rate) # 计算泊松分布
print(rv.pmf(0)) # 发送0次的概率

# 打印发送0-10次的概率列表
k = np.arange(0, 10)
print(rv.pmf(k))

# 使用matplotlib绘制出概率分布
plt.plot(k, rv.pmf(k), 'o-')
plt.title('Piosson: rate=%d' % (rate), fontsize=15)
plt.xlabel('Number of occur')
plt.ylabel('Probability of occur', fontsize=15)
plt.show()
