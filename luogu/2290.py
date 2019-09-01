'''
    Name: luogu P2290
    Author: StudyingFather
    Date: 2019/08/13 16:22
    Website: https://studyingfather.com
'''
n=int(input())
s=input().split()
if n==1 :
    if int(s[0])==0 :
        print(1)
    else :
        print(0)
else :
    f=[1]
    for i in range(1,n+1):
        f.append(f[i-1]*i)
    ans=f[n-2]
    cnt=0
    for i in range(n):
        cnt=cnt+int(s[i])
        ans=ans//f[int(s[i])-1]
    if cnt!=2*n-2 :
        print(0)
    else :
        print(ans)