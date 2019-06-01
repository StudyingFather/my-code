#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
struct edge
{
 int v,next;
}e[10005];
int dfn[105],low[105],head[105],vis[105],col[105],in[105],out[105];
int cnte,cntp,cntc;
stack<int> s;
void addedge(int u,int v)
{
 e[++cnte].v=v;
 e[cnte].next=head[u];
 head[u]=cnte;
}
void dfs(int x)
{
 dfn[x]=low[x]=++cntp;
 vis[x]=1;
 s.push(x);
 for(int i=head[x];i;i=e[i].next)
 {
  if(!dfn[e[i].v])
  {
   dfs(e[i].v);
   low[x]=min(low[x],low[e[i].v]);
  }
  else if(vis[e[i].v])low[x]=min(low[x],dfn[e[i].v]);
 }
 if(dfn[x]==low[x])
 {
  cntc++;
  while(1)
  {
   int p=s.top();
   s.pop();
   vis[p]=false;
   col[p]=cntc;
   if(x==p)break;
  }
 }
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int x;
  while((~scanf("%d",&x)&&x))
   addedge(i,x);
 }
 for(int i=1;i<=n;i++)
  if(!dfn[i])dfs(i);
 for(int i=1;i<=n;i++)
  for(int j=head[i];j;j=e[j].next)
   if(col[i]!=col[e[j].v])
   {
    out[col[i]]++;
    in[col[e[j].v]]++;
   }
 int ans1=0,ans2=0;
 for(int i=1;i<=cntc;i++)
 {
  if(!in[i])ans1++;
  if(!out[i])ans2++;
 }
 printf("%d\n",ans1);
 if(cntc==1)puts("0");
 else printf("%d\n",max(ans1,ans2));
 return 0;
}