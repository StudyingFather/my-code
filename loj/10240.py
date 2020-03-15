def f(n):
    ans=1
    for i in range(1,n+1):
        ans=ans*i
    return ans

n=int(input())
print(f(2*n)//f(n)//f(n)//(n+1))