'''
    Name: Google Code Jam 2019 Qualification Round Problem A
    Author: StudyingFather
    Date: 2019/08/31 23:35
    Website: https://studyingfather.com
'''
t=int(input())
for i in range(t):
    n=int(input())
    x=0
    y=0
    k=1
    while n>0:
        if n%10==4:
            x=x+2*k
            y=y+2*k
        else:
            x=x+n%10*k
        k=k*10
        n=n//10
    print("Case #",i+1,": ",x," ",y,sep='')
