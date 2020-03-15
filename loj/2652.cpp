#include <iostream>
#include <algorithm>
#define N 50000
using namespace std;
int mu[50005],vis[50005],pri[50005];
void init()
{
 int cnt=0;
 mu[1]=vis[1]=1;
 for(int i=2;i<=N;i++)
 {
  if(!vis[i])
   mu[i]=-1,pri[++cnt]=i;
  for(long long j=1;j<=cnt&&pri[j]*i<=N;j++)
  {
   int x=pri[j]*i;
   vis[x]=1;
   if(i%pri[j]==0)
   {
    mu[x]=0;
    break;
   }
   else
    mu[x]=-mu[i];
  }
 }
 for(int i=1;i<=N;i++)
  mu[i]+=mu[i-1];
}
int main()
{
 int t;
 cin>>t;
 init();
 while(t--)
 {
  int n,m,d;
  long long ans=0;
  cin>>n>>m>>d;
  if(n>m)swap(n,m);
  n/=d,m/=d;
  for(int l=1,r;l<=n;l=r+1)
  {
   r=min(n/(n/l),m/(m/l));
   ans+=(long long)(mu[r]-mu[l-1])*(n/l)*(m/l);
  }
  cout<<ans<<endl;
 }
 return 0;
}