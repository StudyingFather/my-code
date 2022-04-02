# Problem: P3223 [HNOI2012]排队
# Contest: Luogu
# URL: https://www.luogu.com.cn/problem/P3223
# Memory Limit: 128 MB
# Time Limit: 1000 ms
#
# Powered by CP Editor (https://cpeditor.org)

f = [1]


def A(n, m):
    if (n < m):
        return 0
    else:
        return f[n] // f[n - m]


s = input().split()
n = int(s[0])
m = int(s[1])
for i in range(1, 4005):
    f.append(f[i - 1] * i)
print(A(n + 3, m) * f[n + 2] - A(n + 2, m) * f[n + 1] * 2)
