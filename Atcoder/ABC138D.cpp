/*
 Name: Atcoder Beginner Contest 138D
 Author: StudyingFather
 Date: 2019/08/18 20:15
 Website: https://studyingfather.com
*/
#include <cstdio>
struct edge
{
 int v,next;
}e[400005];
int head[200005],add[200005],ans[200005],cnt;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u,int fa,int val)
{
 ans[u]=val;
 for(int i=head[u];i;i=e[i].next)
  if(e[i].v!=fa)dfs(e[i].v,u,val+add[e[i].v]);
}
int main()
{
 int n,q;
 scanf("%d%d",&n,&q);
 for(int i=1;i<n;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v);
  addedge(v,u);
 }
 for(int i=1;i<=q;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  add[x]+=y;
 }
 dfs(1,0,add[1]);
 for(int i=1;i<=n;i++)
  printf("%d ",ans[i]);
 return 0;
}
