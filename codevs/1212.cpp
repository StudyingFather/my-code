#include <stdio.h>
int gcd(int m,int n)
{
 if(m%n==0)return n;
 return gcd(n,m%n);
}
int main()
{
 int n,m;
 scanf("%d %d",&m,&n);
 printf("%d",gcd(m,n));
 return 0;
}
