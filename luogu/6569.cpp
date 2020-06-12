// Problem : P6569 [NOI Online #3 提高组]魔法值（民间数据）
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P6569
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
using namespace std;
struct mat
{
 unsigned a[105][105];
 int x,y;
 mat(int X=0,int Y=0)
 {
  memset(a,0,sizeof(a));
  x=X,y=Y;
 }
 mat operator*(const mat&b)const
 {
  mat ans(x,b.y);
  for(int k=1;k<=y;k++)
   for(int i=1;i<=x;i++)
    for(int j=1;j<=b.y;j++)
     ans.a[i][j]^=a[i][k]*b.a[k][j];
  return ans;
 }
}f,e[35];
int main()
{
 int n,m,q;
 cin>>n>>m>>q;
 for(int i=1;i<=n;i++)
  cin>>f.a[1][i];
 f.x=1,f.y=n;
 for(int i=1;i<=m;i++)
 {
  int u,v;
  cin>>u>>v;
  e[0].a[u][v]=e[0].a[v][u]=1;
 }
 e[0].x=e[0].y=n;
 for(int i=1;i<=31;i++)
  e[i]=e[i-1]*e[i-1],e[i].x=e[i].y=n;
 while(q--)
 {
  unsigned x;
  cin>>x;
  mat res=f;
  for(int i=31;i>=0;i--)
   if(x>=1u<<i)
   {
    res=res*e[i];
    x-=1u<<i;
   }
  cout<<res.a[1][1]<<endl;
 }
 return 0;
}