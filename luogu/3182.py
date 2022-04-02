# Problem: P3182 [HAOI2016]放棋子
# Contest: Luogu
# URL: https://www.luogu.com.cn/problem/P3182
# Memory Limit: 125 MB
# Time Limit: 1000 ms
#
# Powered by CP Editor (https://cpeditor.org)

n = int(input())
res = [0, 0, 1]
for i in range(3, n + 1):
    res.append((i - 1) * (res[i - 1] + res[i - 2]))
print(res[n])
