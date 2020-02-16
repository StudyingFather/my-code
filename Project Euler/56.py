ans=0
for a in range(1,101):
    for b in range(1,101):
        x=a**b
        res=0
        while x>0:
            res=res+x%10
            x=x//10
        if res>ans:
            ans=res
print(ans)
