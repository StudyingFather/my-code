// Problem: P3524 [POI2011]IMP-Party
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3524
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int f[3005][3005],vis[3005];
int main()
{
 ios::sync_with_stdio(false);
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
  int u,v;
  cin>>u>>v;
  f[u][v]=f[v][u]=1;
 }
 for(int i=1;i<=n;i++)
 {
  if(vis[i])continue;
  for(int j=1;j<=n;j++)
  {
   if(i==j||vis[j])continue;
   if(!f[i][j])
   {
    vis[i]=vis[j]=1;
    break;
   }
  }
 }
 int cnt=0;
 for(int i=1;i<=n;i++)
  if(!vis[i])
  {
   cout<<i<<' ';
   cnt++;
   if(cnt==n/3)break;
  }
 return 0;
}