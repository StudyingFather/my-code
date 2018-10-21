#include <stdio.h>
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int a;
  scanf("%d",&a);
  if(a==0)puts("1");
  else
  {
   int cnt=1;
   while(a!=0)
   {
    if(a%2)cnt*=2;
    a>>=1;
   }
   printf("%d\n",cnt);
  }
 }
 return 0;
}
