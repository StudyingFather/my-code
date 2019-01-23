ans=0
num=2**1000
while num>0:
    ans+=num%10
    num//=10
print(ans)
