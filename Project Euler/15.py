def frac(n):
    ans = 1
    for i in range(1, n+1):
        ans = ans * i
    return ans

print(frac(40) // frac(20) // frac(20))
