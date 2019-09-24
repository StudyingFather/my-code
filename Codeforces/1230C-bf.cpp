/*
 Name: Codeforces 1230C (brute force solution)
 Author: StudyingFather
 Date: 2019/09/24 00:24
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[15][15],g[15][15],col[15],n,m,ans;
void dfs(int d)
{
 if(d==n+1)
 {
  int res=0;
  memset(g,0,sizeof(g));
  for(int i=1;i<=n;i++)
   for(int j=i;j<=n;j++)
    if((!g[col[i]][col[j]])&&f[i][j])
    {
     res++;
     g[col[i]][col[j]]=g[col[j]][col[i]]=1;
    }
  ans=max(ans,res);
  return;
 }
 for(int i=1;i<=6;i++)
 {
  col[d]=i;
  dfs(d+1);
  col[d]=0;
 }
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  f[x][y]=f[y][x]=1;
 }
 if(n<=6)printf("%d\n",m);
 else
 {
  dfs(1);
  printf("%d\n",ans);
 }
 return 0;
}