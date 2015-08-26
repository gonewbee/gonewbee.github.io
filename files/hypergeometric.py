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
