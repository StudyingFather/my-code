#include <stdio.h>
int lowbit(int x)
{
 return x&(-x);
}
int calc(int x)
{
 int cnt=0;
 for(;x;x-=lowbit(x))
  cnt++;
 return cnt;
}
int main()
{
 int n,k,ans=0;
 scanf("%d%d",&n,&k);
 while(calc(n)>k)
 {
  ans+=lowbit(n);
  n+=lowbit(n);
 }
 printf("%d\n",ans);
 return 0;
}