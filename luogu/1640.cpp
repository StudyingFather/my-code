/*
 Name: luogu P1640
 Author: StudyingFather
 Date: 2019/09/28 23:18
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
struct edge
{
 int v,next;
}e[2000005];
int head[10005],res[1000005],cnt;
bool vis[1000005];
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool dfs(int u)
{
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(!vis[v])
  {
   vis[v]=1;
   if(!res[v]||dfs(res[v]))
   {
    res[v]=u;
    return true;
   }
  }
 }
 return false;
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  addedge(x,i);
  addedge(y,i);
 }
 for(int i=1;i<=10000;i++)
 {
  memset(vis,0,sizeof(vis));
  if(!dfs(i))
  {
   printf("%d\n",i-1);
   return 0;
  }
 }
 puts("10000");
 return 0;
}