m=int(input())
n=int(input())
l=0
r=1
while(r**m<=n):
    l=r
    r=r*2
while(l+1<r):
    mid=(l+r)//2
    if(mid**m<=n):
        l=mid
    else:
        r=mid
if(l**m<=n):
    print(l)
else:
    print(r)
