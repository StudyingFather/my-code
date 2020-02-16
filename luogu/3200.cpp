#include <iostream>
using namespace std;
int f[2000005],pri[2000005],vis[2000005],cnt,n,p;
long long fpow(long long x,long long y)
{
 long long ans=1;
 while(y)
 {
  if(y&1)ans=ans*x%p;
  x=x*x%p;
  y>>=1;
 }
 return ans;
}
int main()
{
 long long ans=1;
 cin>>n>>p;
 for(int i=2;i<=2*n;i++)
 {
  if(!vis[i])
  {
   pri[++cnt]=i;
   vis[i]=i;
  }
  for(int j=1;j<=cnt&&i*pri[j]<=2*n;j++)
  {
   vis[i*pri[j]]=pri[j];
   if(i%pri[j]==0)break;
  }
 }
 for(int i=1;i<=n;i++)
  f[i]=-1;
 for(int i=n+2;i<=2*n;i++)
  f[i]=1;
 for(int i=2*n;i>=2;i--)
  if(vis[i]!=i)
  {
   f[vis[i]]+=f[i];
   f[i/vis[i]]+=f[i];
  }
 for(int i=2;i<=2*n;i++)
  if(vis[i]==i)
   ans=ans*fpow(i,f[i])%p;
 cout<<ans<<endl;
 return 0;
}