#include <stdio.h>
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n,k,minc,cnt;
  scanf("%d%d",&n,&k);
  minc=n/k;
  cnt=n-n/k*k;
  for(int i=1;i<=k;i++)
  {
   for(int j=1;j<=minc+(cnt>0?1:0);j++)
    putchar('a'+i-1);
   if(cnt>0)cnt--;
  }
  puts("");
 }
 return 0;
}
