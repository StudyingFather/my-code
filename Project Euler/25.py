maxx=10**999
f=[0,1,1]
cur=3
while f[cur-1]<maxx:
    f.append(f[cur-1]+f[cur-2])
    cur+=1
print(cur-1)
