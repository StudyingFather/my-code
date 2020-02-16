#include <iostream>
#define MOD 1000000007
#define INV 500000004
using namespace std;
long long f[3005][3005],g[3005],h[3005];
int a[3005];
int main()
{
 int n,q;
 cin>>n>>q;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   if(a[i]>a[j])f[i][j]=1;
 long long ans=0,tmp=1;
 while(q--)
 {
  int x,y;
  cin>>x>>y;
  for(int i=1;i<=n;i++)
  {
   g[i]=(f[x][i]+f[y][i])*INV%MOD;
   h[i]=(f[i][x]+f[i][y])*INV%MOD;
  }
  for(int i=1;i<=n;i++)
  {
   f[x][i]=f[y][i]=g[i];
   f[i][x]=f[i][y]=h[i];
  }
  tmp=tmp*2%MOD;
  f[x][x]=f[y][y]=0;
  f[x][y]=f[y][x]=(f[x][y]+f[y][x])%MOD;
 }
 for(int i=1;i<=n;i++)
  for(int j=i+1;j<=n;j++)
   ans=(ans+f[i][j])%MOD;
 cout<<ans*tmp%MOD<<endl;
 return 0;
}
