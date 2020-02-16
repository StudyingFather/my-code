res=1
for i in range (1,101):
    res*=i
ans=0
while(res!=0):
    ans+=res%10
    res//=10
print(ans)
