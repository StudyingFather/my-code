#include <stdio.h>
bool is_prime(int num)
{
 if(num<=1)return false;
 for(int i=2;i*i<=num;i++)
  if(num%i==0)return false;
 return true;
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=2;i<=n;i++)
  for(int j=2;i+j<=n;j++)
   if(is_prime(i)&&is_prime(j)&&is_prime(n-i-j))
   {
    printf("%d %d %d",i,j,n-i-j);
    return 0;
   }
}
