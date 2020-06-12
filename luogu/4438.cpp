// Problem : P4438 [HNOI/AHOI2018]道路
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P4438
// Memory Limit : 500 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
using namespace std;
long long f[40001][41][41],a[20005],b[20005],c[20005];
int son[20005][2],n;
void dfs(int u,int x,int y)
{
 if(u>n)
 {
  u-=n;
  for(int i=0;i<=x;i++)
   for(int j=0;j<=y;j++)
    f[u+n][i][j]=c[u]*(a[u]+i)*(b[u]+j);
  return;
 }
 dfs(son[u][0],x+1,y);
 dfs(son[u][1],x,y+1);
 for(int i=0;i<=x;i++)
  for(int j=0;j<=y;j++)
   f[u][i][j]=min(f[son[u][0]][i+1][j]+f[son[u][1]][i][j],f[son[u][0]][i][j]+f[son[u][1]][i][j+1]);
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n;
 for(int i=1;i<n;i++)
 {
  cin>>son[i][0]>>son[i][1];
  if(son[i][0]<0)son[i][0]=-son[i][0]+n;
  if(son[i][1]<0)son[i][1]=-son[i][1]+n;
 }
 for(int i=1;i<=n;i++)
  cin>>a[i]>>b[i]>>c[i];
 dfs(1,0,0);
 cout<<f[1][0][0]<<endl;
 return 0;
}