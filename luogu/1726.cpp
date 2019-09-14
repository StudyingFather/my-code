/*
 Name: luogu P1726
 Author: StudyingFather
 Date: 2019/09/09 18:45
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
struct node
{
 int v,next;
}e[100005];
stack<int> s;
int head[5005],dfn[5005],low[5005],vis[5005],cnte,cntp,res[5005],tmp[5005],ans;
void addedge(int u,int v)
{
 e[++cnte].v=v;
 e[cnte].next=head[u];
 head[u]=cnte;
}
int cmp()
{
 for(int i=1;i<=ans;i++)
  if(tmp[i]<res[i])return 1;
  else if(tmp[i]>res[i])return -1;
 return 0;
}
void dfs(int u)
{
 dfn[u]=low[u]=++cntp;
 vis[u]=1;
 s.push(u);
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(!dfn[v])
  {
   dfs(v);
   low[u]=min(low[u],low[v]);
  }
  else if(vis[v])low[u]=min(low[u],dfn[v]);
 }
 if(dfn[u]==low[u])
 {
  int num=0;
  while(1)
  {
   int p=s.top();
   s.pop();
   tmp[++num]=p;
   vis[p]=0;
   if(p==u)break;
  }
  sort(tmp+1,tmp+num+1);
  if(num>ans)
  {
   ans=num;
   memcpy(res,tmp,sizeof(tmp));
  }
  else if(num==ans&&cmp()==1)memcpy(res,tmp,sizeof(tmp));
 }
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int u,v,t;
  scanf("%d%d%d",&u,&v,&t);
  if(t==2)addedge(u,v),addedge(v,u);
  else addedge(u,v);
 }
 for(int i=1;i<=n;i++)
  if(!dfn[i])dfs(i);
 printf("%d\n",ans);
 for(int i=1;i<=ans;i++)
  printf("%d ",res[i]);
 return 0;
}