#include <stdio.h>
bool is_prime(int num)
{
 if(num==1)return false;
 for(int i=2;i*i<=num;i++)
  if(num%i==0)return false;
 return true;
}
int main()
{
 int cnt=0;
 for(int i=2;;i++)
 {
  if(is_prime(i))cnt++;
  if(cnt==10001)
  {
   printf("%d",i);
   return 0;
  }
 }
}
