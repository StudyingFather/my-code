#include<stdio.h>
int gcd(int x,int y)
{
 return y==0?x:gcd(y,x%y);
}
int main()
{
 int n,m;
 while(scanf("%d%d",&n,&m)==2)
 {
  printf("%10d%10d",n,m);
  if(gcd(n,m)==1)printf("    Good Choice\n\n");
  else printf("    Bad Choice\n\n");
 }
 return 0;
}
