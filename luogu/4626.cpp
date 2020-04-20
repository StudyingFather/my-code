#include <cstdio>
#include <iostream>
#include <bitset>
#define MOD 100000007
using namespace std;
bitset<100000005> vis;
int pri[6000005],f[6000005],cnt;
int main()
{
 int n;
 long long ans=1;
 cin>>n;
 for(int i=2;i<=n;i++)
 {
  if(!vis[i])
  {
   pri[++cnt]=i;
   ans=ans*i%MOD;
   f[cnt]=i;
  }
  for(int j=1;j<=cnt&&i*pri[j]<=n;j++)
  {
   vis[i*pri[j]]=1;
   if(i%pri[j]==0)
   {
    if(f[j]==i)
    {
     f[j]=f[j]*pri[j];
     ans=ans*pri[j]%MOD;
    }
    break;
   }
  }
 }
 cout<<ans<<endl;
 return 0;
}