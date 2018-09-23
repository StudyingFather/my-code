#include <stdio.h>
#include <math.h>
int a;
int is_prime(int n)
{
 if(n==1)return 0;
 for(int i=2;i<=(int)sqrt(n);i++)
  if(n%i==0)return 0;
 return 1;
}
int main()
{
 scanf("%d",&a);
 if(is_prime(a))
 {
  putchar('\\');
  putchar('t');
 }
 else
 {
  putchar('\\');
  putchar('n');
 }
 return 0;
}
