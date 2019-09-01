'''
    Name: loj 10208
    Author: StudyingFather
    Date: 2019/08/12 20:08
    Website: https://studyingfather.com
'''
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