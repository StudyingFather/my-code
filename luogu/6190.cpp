#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct edge
{
 int u,v,w;
}e[2505];
int n,m,k;
struct mat
{
 long long a[105][105];
 mat(int x=63)
 {
  memset(a,x,sizeof(a));
 }
 mat operator*(const mat&b)const
 {
  mat ans;
  for(int k=1;k<=n;k++)
   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
     ans.a[i][j]=min(ans.a[i][j],a[i][k]+b.a[k][j]);
  return ans;
 }
}a;
long long f[105][105];
mat fpow(mat x,int y)
{
 mat ans;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   ans.a[i][j]=f[i][j];
 while(y)
 {
  if(y&1)ans=ans*x;
  x=x*x;
  y>>=1;
 }
 return ans;
}
int main()
{
 memset(f,63,sizeof(f));
 cin>>n>>m>>k;
 for(int i=1;i<=n;i++)
  f[i][i]=0;
 for(int i=1;i<=m;i++)
 {
  cin>>e[i].u>>e[i].v>>e[i].w;
  f[e[i].u][e[i].v]=e[i].w;
 }
 for(int k=1;k<=n;k++)
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
 for(int k=1;k<=m;k++)
 {
  int u=e[k].u,v=e[k].v,w=e[k].w;
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    a.a[i][j]=min(a.a[i][j],min(f[i][j],f[i][u]+f[v][j]-w));
 }
 if(k==0)cout<<f[1][n]<<endl;
 else cout<<fpow(a,k).a[1][n]<<endl;
 return 0;
}