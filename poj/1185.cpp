#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,ans,dp[1025][1025][3],a[105],sum[1025];
char x;
int getsum(int s)
{
 int tot=0;
 while(s)
 {
  if(s&1)tot++; 
  s>>=1;
 }
 return tot;
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)
  {
   scanf("\n%c",&x);
   a[i]<<=1;
   a[i]+=(x=='H'?1:0); 
  }
 for(int i=0;i<(1<<m);i++)
  sum[i]=getsum(i);
 for(int s=0;s<(1<<m);s++)
  if(!(s&a[0]||(s&(s<<1))||(s&(s<<2))))
   dp[0][s][0]=sum[s];
 for(int l=0;l<(1<<m);l++)
  for(int s=0;s<(1<<m);s++)
   if(!(l&s||l&a[0]||s&a[1]||(l&(l<<1))||(l&(l<<2))||(s&(s<<1))||(s&(s<<2))))
    dp[l][s][1]=sum[s]+sum[l];
 for(int i=2;i<n;i++)
  for(int l=0;l<(1<<m);l++)
  {
   if(l&a[i-1]||(l&(l<<1))||(l&(l<<2)))continue;
   for(int s=0;s<(1<<m);s++)
   {
    if(s&a[i]||l&s||(s&(s<<1))||(s&(s<<2)))continue;
    for(int fl=0;fl<(1<<m);fl++)
    {
     if(fl&l||fl&s||fl&a[i-2]||(fl&(fl<<1))||(fl&(fl<<2)))continue;
     dp[l][s][i%3]=max(dp[l][s][i%3],dp[fl][l][(i-1)%3]+sum[s]);//¹ö¶¯Êý×é
    }
   }
  }
 for(int l=0;l<(1<<m);l++)
  for(int s=0;s<(1<<m);s++)
   ans=max(ans,dp[l][s][(n-1)%3]);
 printf("%d",ans);
 return 0;
}
