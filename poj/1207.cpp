#include <stdio.h>
int i,j,maxn,num;
int jisuan(int n)
{
 int ans=1;
 while(n!=1)
 {
  if(n%2==0)n/=2;
  else n=3*n+1;
  ans++;
 }
 return ans;
}
int main()
{
 while(scanf("%d%d",&i,&j)==2)
 {
  maxn=0;
  printf("%d %d ",i,j);
  if(i>j)
  {
   int t=i;
   i=j;
   j=t;
  }
  for(int k=i;k<=j;k++)
  {
   num=jisuan(k);
   if(num>maxn)maxn=num;
  }
  printf("%d\n",maxn);
 }
 return 0;
}
