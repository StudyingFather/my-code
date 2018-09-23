#include <stdio.h>
#include <math.h>
int is_prime(int a)
{
 if(a==1)return 0;
 int s=sqrt(a);
 for(int i=2;i<=s;i++)
  if(a%i==0)return 0;
 return 1;
}
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int m,n;
  scanf("%d%d",&m,&n);
  for(int i=m;i<=n;i++)
   if(is_prime(i))printf("%d\n",i);
  if(t)puts("");
 }
 return 0;
}
