def gcd(x,y):
    while(x!=0):
        y=y%x
        t=x
        x=y
        y=t
    return y

x=int(input())
y=int(input())
print(gcd(x,y))
