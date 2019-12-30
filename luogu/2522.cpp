#include <cstdio>
#include <algorithm>
using namespace std;
int mu[50005],vis[50005],pri[50005],sum[50005],cnt;
int calc(int x,int y)
{
 if(x>y)swap(x,y);
 int ans=0;
 for(int l=1,r;l<=x;l=r+1)
 {
  r=min(x/(x/l),y/(y/l));
  ans+=(sum[r]-sum[l-1])*(x/l)*(y/l);
 }
 return ans;
}
int main()
{
 int t;
 scanf("%d",&t);
 mu[1]=1;
 for(int i=2;i<=50000;i++)
 {
  if(!vis[i])pri[++cnt]=i,mu[i]=-1;
  for(int j=1;j<=cnt&&i*pri[j]<=50000;j++)
  {
   vis[i*pri[j]]=1;
   if(i%pri[j]==0)
   {
    mu[i*pri[j]]=0;
    break;
   }
   mu[i*pri[j]]=-mu[i];
  }
 }
 for(int i=1;i<=50000;i++)
  sum[i]=sum[i-1]+mu[i];
 while(t--)
 {
  int a,b,c,d,k;
  scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
  printf("%d\n",
   calc(b/k,d/k)-calc(b/k,(c-1)/k)-calc((a-1)/k,d/k)+calc((a-1)/k,(c-1)/k));
 }
 return 0;
}