#include <cstdio>
#include <algorithm>
using namespace std;
int v[1000005],son[1000005][2],size[1000005];
void dfs(int u)
{
 size[u]=1;
 if(~son[u][0])
 {
  dfs(son[u][0]);
  size[u]+=size[son[u][0]];
 }
 if(~son[u][1])
 {
  dfs(son[u][1]);
  size[u]+=size[son[u][1]];
 }
}
bool judge(int x,int y)
{
 if(x==y&&x==-1)return true;
 if(x!=-1&&y!=-1&&v[x]==v[y]&&judge(son[x][0],son[y][1])&&judge(son[y][0],son[x][1]))return true;
 return false;
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&v[i]);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&son[i][0],&son[i][1]);
 dfs(1);
 int maxs=1;
 for(int i=1;i<=n;i++)
  if(judge(son[i][0],son[i][1]))maxs=max(maxs,size[i]);
 printf("%d\n",maxs);
 return 0;
}