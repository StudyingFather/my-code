#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;
struct mat
{
 long long x[505][505];
 mat()
 {
  memset(x,0,sizeof(x));
 }
}a,b,ans;
int main()
{
 int n,p,m;
 cin>>n>>p>>m;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=p;j++)
   cin>>a.x[i][j];
 for(int i=1;i<=p;i++)
  for(int j=1;j<=m;j++)
   cin>>b.x[i][j];
 for(int k=1;k<=p;k++)
  for(int i=1;i<=n;i++)
   for(int j=1;j<=m;j++)
    ans.x[i][j]=(ans.x[i][j]+a.x[i][k]*b.x[k][j])%MOD;
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=m;j++)
  {
   if(ans.x[i][j]<0)ans.x[i][j]+=MOD;
   cout<<ans.x[i][j]<<' ';
  }
  cout<<endl;
 }
 return 0;
}