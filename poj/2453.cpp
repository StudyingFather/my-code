#include <stdio.h>
int calc(int n)
{
 int ans=0;
 while(n)
 {
  if(n%2==1)ans++;
  n>>=1;
 }
 return ans;
}
int main()
{
 int i;
 while(~scanf("%d",&i)&&i)
 {
  int a=calc(i);
  for(int j=i+1;;j++)
  {
   int b=calc(j);
   if(a==b)
   {
    printf("%d\n",j);
    break;
   }
  }
 }
 return 0;
}
