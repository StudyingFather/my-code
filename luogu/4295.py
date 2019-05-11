s=input().split()
n=int(s[0])
d=int(s[1])
f=[1]
if(d==0):
    print(1)
else:
    for i in range(1,d+1):
        f.append(f[i-1]**n+1)
    print(f[d]-f[d-1])
