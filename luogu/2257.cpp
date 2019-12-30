#include <iostream>
#include <algorithm>
#define N 10000000
using namespace std;
int mu[10000005],vis[10000005],pri[10000005];
long long f[10000005];
void init()
{
 int cnt=0;
 mu[1]=vis[1]=1;
 for(int i=2;i<=N;i++)
 {
  if(!vis[i])
   mu[i]=-1,f[i]=1,pri[++cnt]=i;
  for(long long j=1;j<=cnt&&pri[j]*i<=N;j++)
  {
   int x=pri[j]*i;
   vis[x]=1;
   if(i%pri[j]==0)
   {
    f[x]=mu[i],mu[x]=0;
    break;
   }
   else
    f[x]=-f[i]+mu[i],mu[x]=-mu[i];
  }
  f[i]+=f[i-1];
 }
}
int main()
{
 int t;
 cin>>t;
 init();
 while(t--)
 {
  int n,m;
  long long ans=0;
  cin>>n>>m;
  if(n>m)swap(n,m);
  for(int l=1,r;l<=n;l=r+1)
  {
   r=min(n/(n/l),m/(m/l));
   ans+=(f[r]-f[l-1])*(n/l)*(m/l);
  }
  cout<<ans<<endl;
 }
 return 0;
}