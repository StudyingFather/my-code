# Problem: #2061. 「HAOI2016」放棋子
# Contest: LibreOJ
# URL: https://loj.ac/p/2061
# Memory Limit: 256 MB
# Time Limit: 1000 ms
#
# Powered by CP Editor (https://cpeditor.org)

n = int(input())
res = [0, 0, 1]
for i in range(3, n + 1):
    res.append((i - 1) * (res[i - 1] + res[i - 2]))
print(res[n])
