// Problem : #2178. 「BJOI2017」机动训练
// Contest : LibreOJ
// URL : https://loj.ac/problem/2178
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstdio>
#include <cstring>
#include <vector>
#define MOD 1000000009
using namespace std;
int f[5][5][5][5],g[35][35][35][35];
int m,n;
char s[35][35];
vector<pair<int,int> > a,b;
int dp(int x,int y,int r,int c)
{
 if(s[x][y]!=s[r][c])return 0;
 if(x<1||x>m||y<1||y>n||r<1||r>m||c<1||c>n)return 0;
 if(~g[x][y][r][c])return g[x][y][r][c];
 int ans=1;
 for(auto i:a)
  for(auto j:b)
  {
   int dx=i.first,dy=i.second,dr=j.first,dc=j.second;
   ans=(ans+dp(x+dx,y+dy,r+dr,c+dc))%MOD;
  }
 return g[x][y][r][c]=ans;
}
int dfs(int x,int y,int p,int q)
{
 if(~f[x+1][y+1][p+1][q+1])
  return f[x+1][y+1][p+1][q+1];
 a.clear(),b.clear();
 for(int i=-1;i<=1;i++)
  if(!i||i==x)
   for(int j=-1;j<=1;j++)
    if((i||j)&&(!j||j==y))
     a.emplace_back(i,j);
 for(int i=-1;i<=1;i++)
  if(!i||i==p)
   for(int j=-1;j<=1;j++)
    if((i||j)&&(!j||j==q))
     b.emplace_back(i,j);
 memset(g,-1,sizeof(g));
 int ans=0;
 for(int i=1;i<=m;i++)
  for(int j=1;j<=n;j++)
   for(int r=1;r<=m;r++)
    for(int c=1;c<=n;c++)
     ans=(ans+dp(i,j,r,c))%MOD;
 f[x+1][y+1][p+1][q+1]=f[p+1][q+1][x+1][y+1]=ans;
 f[-x+1][-y+1][-p+1][-q+1]=f[-p+1][-q+1][-x+1][-y+1]=ans;
 return ans;
}
int calc(int x,int y)
{
 int ans=0;
 ans=(ans+dfs(x,y,1,1))%MOD;
 ans=(ans+dfs(x,y,1,-1))%MOD;
 ans=(ans+dfs(x,y,-1,1))%MOD;
 ans=(ans+dfs(x,y,-1,-1))%MOD;
 ans=(ans-dfs(x,y,1,0)+MOD)%MOD;
 ans=(ans-dfs(x,y,-1,0)+MOD)%MOD;
 ans=(ans-dfs(x,y,0,1)+MOD)%MOD;
 ans=(ans-dfs(x,y,0,-1)+MOD)%MOD;
 return ans;
}
int main()
{
 memset(f,-1,sizeof(f));
 scanf("%d%d",&m,&n);
 for(int i=1;i<=m;i++)
  scanf("%s",s[i]+1);
 int ans=0;
 ans=(ans+calc(1,1))%MOD;
 ans=(ans+calc(1,-1))%MOD;
 ans=(ans+calc(-1,1))%MOD;
 ans=(ans+calc(-1,-1))%MOD;
 ans=(ans-calc(1,0)+MOD)%MOD;
 ans=(ans-calc(-1,0)+MOD)%MOD;
 ans=(ans-calc(0,1)+MOD)%MOD;
 ans=(ans-calc(0,-1)+MOD)%MOD;
 printf("%d\n",ans);
 return 0;
}