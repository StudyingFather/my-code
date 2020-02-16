ans=0
for i in range (1,101):
    ans+=int(input())
while ans>= 10**10:
    ans//=10
print(ans)
