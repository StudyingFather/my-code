'''
    Name: luogu P4157
    Author: StudyingFather
    Date: 2019/08/11 10:41
    Website: https://studyingfather.com
'''
from math import *
n=int(input())
ans=1
while n>4 :
    n=n-3
    ans=ans*3
if n==4 :
    ans=ans*4
elif n==3 :
    ans=ans*3
elif n==2:
    ans=ans*2
x=int(log(ans)/log(10))+1
print(x)
if x<=100 :
    print(ans)
else :
    while x>100 :
        ans=ans//10
        x=x-1
    print(ans)