#include <stdio.h>
#include <math.h>
int is_prime(int n)
{
 int maxn=floor(sqrt(n)+0.5);
 for(int i=2;i<=maxn;i++)
  if(n%i==0)return 0;
 return 1;
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=2;;i++)
  if(is_prime(i)&&n%i==0)
  {
   printf("%d",n/i);
   break;
  }
 return 0;
}
