#include <iostream>
#include <algorithm>
using namespace std;
int phi[10000005],p[10000005],cnt;
long long sum[10000005];
bool vis[10000005];
int main()
{
 long long n,ans=0;
 cin>>n;
 phi[1]=1;
 for(int i=2;i<=n;i++)
 {
  if(!vis[i])
  {
   p[++cnt]=i;
   phi[i]=i-1;
  }
  for(int j=1;j<=cnt&&i*p[j]<=n;j++)
  {
   vis[i*p[j]]=1;
   if(i%p[j]==0)
   {
    phi[i*p[j]]=phi[i]*p[j];
    break;
   }
   else phi[i*p[j]]=phi[i]*phi[p[j]];
  }
 }
 for(int i=1;i<=n;i++)
  sum[i]=sum[i-1]+phi[i];
 for(int i=1;i<=cnt;i++)
  ans+=2*sum[n/p[i]]-1;
 cout<<ans<<endl;
 return 0;
}