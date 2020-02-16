#include <iostream>
#include <unordered_map>
#define MAXN 2000000
using namespace std;
long long mu[MAXN+5],phi[MAXN+5],pri[MAXN+5];
int vis[MAXN+5],cnt;
unordered_map<int,long long> muans,phians;
long long phi_sum(long long x)
{
 if(x<=MAXN)return phi[x];
 if(phians.count(x))return phians[x];
 long long ans=x*(x+1)/2;
 for(long long l=2,r;l<=x;l=r+1)
 {
  r=x/(x/l);
  ans-=(r-l+1)*phi_sum(x/l);
 }
 return phians[x]=ans;
}
long long mu_sum(long long x)
{
 if(x<=MAXN)return mu[x];
 if(muans.count(x))return muans[x];
 long long ans=1;
 for(long long l=2,r;l<=x;l=r+1)
 {
  r=x/(x/l);
  ans-=(r-l+1)*mu_sum(x/l);
 }
 return muans[x]=ans;
}
int main()
{
 int t;
 cin>>t;
 mu[1]=1,phi[1]=1;
 for(int i=2;i<=MAXN;i++)
 {
  if(!vis[i])
  {
   pri[++cnt]=i;
   phi[i]=i-1;
   mu[i]=-1;
  }
  for(int j=1;i*pri[j]<=MAXN;j++)
  {
   vis[i*pri[j]]=1;
   if(i%pri[j]==0)
   {
    phi[i*pri[j]]=phi[i]*pri[j];
    mu[i*pri[j]]=0;
    break;
   }
   else
   {
    phi[i*pri[j]]=phi[i]*phi[pri[j]];
    mu[i*pri[j]]=-mu[i];
   }
  }
 }
 for(int i=1;i<=MAXN;i++)
  phi[i]+=phi[i-1],mu[i]+=mu[i-1];
 while(t--)
 {
  int n;
  cin>>n;
  cout<<phi_sum(n)<<' '<<mu_sum(n)<<endl;
 }
 return 0;
}