x=1
ans=0
while x<=1000:
    ans=ans+x**x
    ans=ans%(10**10)
    x=x+1
print(ans)