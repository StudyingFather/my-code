#include <iostream>
#define MOD 1000000007
using namespace std;
int pri[1000005],vis[1000005],c[1000005],cnt;
int main()
{
 int n;
 cin>>n;
 long long ans=1;
 for(int i=2;i<=n;i++)
 {
  if(!vis[i])pri[++cnt]=i,vis[i]=i;
  for(int j=1;j<=cnt&&i*pri[j]<=n;j++)
  {
   vis[i*pri[j]]=pri[j];
   if(i%pri[j]==0)break;
  }
 }
 for(int i=1;i<=n;i++)
  for(int j=i;j!=1;j/=vis[j])
   c[vis[j]]++;
 for(int i=1;i<=n;i++)
  ans=ans*(c[i]*2+1)%MOD;
 cout<<ans<<endl;
 return 0;
}