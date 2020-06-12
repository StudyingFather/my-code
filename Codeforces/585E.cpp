// Problem : E. Present for Vitalik the Philatelist
// Contest : Codeforces - Codeforces Round #325 (Div. 1)
// URL : https://codeforces.com/contest/585/problem/E
// Memory Limit : 256 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#define MAXX 10000000
#define MAXN 500000
#define MOD 1000000007
using namespace std;
int vis[MAXX+5],pri[MAXX+5],mu[MAXX+5],cnt;
int x[MAXN+5],t[MAXX+5],a[MAXX+5],p2[MAXN+5];
long long f[MAXN+5],g[MAXN+5];
int main()
{
 ios::sync_with_stdio(false);
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>x[i];
  t[x[i]]++;
 }
 mu[1]=1;
 for(int i=2;i<=MAXX;i++)
 {
  if(!vis[i])
  {
   pri[++cnt]=i;
   mu[i]=-1;
  }
  for(int j=1;j<=cnt&&i*pri[j]<=MAXX;j++)
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
 for(int i=1;i<=MAXX;i++)
  for(int j=i;j<=MAXX;j+=i)
   a[i]+=t[j];
 p2[0]=1;
 for(int i=1;i<=n;i++)
 {
  p2[i]=p2[i-1]*2%MOD;
  f[i]=(2*f[i-1]+p2[i-1])%MOD;
 }
 long long ans=0;
 for(int d=1;d<=MAXX;d++)
 {
  ans=(ans+mu[d]*(f[a[d]]-a[d]))%MOD;
  ans=(ans-mu[d]*(1ll*n*(p2[a[d]]-1)-f[a[d]]))%MOD;
 }
 cout<<(ans+MOD)%MOD<<endl;
 return 0;
}