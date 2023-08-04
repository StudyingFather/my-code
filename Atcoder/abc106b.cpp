#include <stdio.h>
int calc(int num)
{
 int cnt=0;
 for(int i=1;i<=num;i++)
  if(num%i==0)cnt++;
 return cnt;
}
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i+=2)
  if(calc(i)==8)ans++;
 printf("%d",ans);
 return 0;
}
