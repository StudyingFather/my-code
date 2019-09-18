/*
 Name: luogu P2420
 Author: StudyingFather
 Date: 2019/09/18 00:21
 Website: https://studyingfather.com
*/
#include <cstdio>
struct edge
{
 int v,w,next;
}e[200005];
int xsum[100005],head[100005],cnt;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u,int fa)
{
 for(int i=head[u];i;i=e[i].next)
  if(e[i].v!=fa)
  {
   xsum[e[i].v]=xsum[u]^e[i].w;
   dfs(e[i].v,u);
  }
}
int main()
{
 int n,m;
 scanf("%d",&n);
 for(int i=1;i<n;i++)
 {
  int u,v,w;
  scanf("%d%d%d",&u,&v,&w);
  addedge(u,v,w);
  addedge(v,u,w);
 }
 dfs(1,0);
 scanf("%d",&m);
 while(m--)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  printf("%d\n",xsum[x]^xsum[y]);
 }
 return 0;
}