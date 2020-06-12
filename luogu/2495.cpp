// Problem : P2495 [SDOI2011]消耗战
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P2495
// Memory Limit : 500 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
struct graph
{
 struct edge
 {
  int v,w,next;
 }e[1000005];
 int head[500005],ch,cnt;
 void addedge(int u,int v,int w)
 {
  e[++cnt].v=v;
  e[cnt].w=w;
  e[cnt].next=head[u];
  head[u]=cnt;
 }
}t1,t2;
int fa[500005][25],mind[500005][25],dis[500005],dep[500005],dfn[500005],cnt;
int a[500005];
long long f[500005];
int sta[500005];
int d;
set<int> s;
bool cmp(int x,int y)
{
 return dfn[x]<dfn[y];
}
void dfs1(int u,int f)
{
 dfn[u]=++cnt;
 dep[u]=dep[f]+1;
 fa[u][0]=f;
 for(int i=1;i<=20;i++)
 {
  fa[u][i]=fa[fa[u][i-1]][i-1];
  mind[u][i]=min(mind[u][i-1],mind[fa[u][i-1]][i-1]);
 }
 for(int i=t1.head[u];i;i=t1.e[i].next)
 {
  int v=t1.e[i].v,w=t1.e[i].w;
  if(v!=f)
  {
   dis[v]=dis[u]+w;
   mind[v][0]=w;
   dfs1(v,u);
  }
 }
}
void dfs2(int u)
{
 f[u]=0;
 for(int i=t2.head[u];i;i=t2.e[i].next)
 {
  int v=t2.e[i].v,w=t2.e[i].w;
  dfs2(v);
  if(s.count(v))f[u]+=w;
  else f[u]+=min(f[v],1ll*w);
 }
 return;
}
int getlca(int x,int y)
{
 d=1<<30;
 if(dep[x]>dep[y])swap(x,y);
 for(int i=20;i>=0;i--)
  if(dep[y]-(1<<i)>=dep[x])
  {
   d=min(d,mind[y][i]);
   y=fa[y][i];
  }
 if(x==y)return x;
 for(int i=20;i>=0;i--)
  if(fa[x][i]!=fa[y][i])
  {
   d=min(d,min(mind[x][i],mind[y][i]));
   x=fa[x][i],y=fa[y][i];
  }
 return fa[x][0];
}
int main()
{
 ios::sync_with_stdio(false);
 int n;
 cin>>n;
 for(int i=1;i<n;i++)
 {
  int u,v,w;
  cin>>u>>v>>w;
  t1.addedge(u,v,w);
  t1.addedge(v,u,w);
 }
 dfs1(1,1);
 int q;
 cin>>q;
 while(q--)
 {
  s.clear();
  int k;
  cin>>k;
  for(int i=1;i<=k;i++)
  {
   cin>>a[i];
   s.insert(a[i]);
  }
  sort(a+1,a+k+1,cmp);
  sta[1]=1;
  int top=1;
  t2.head[1]=0;
  for(int i=1;i<=k;i++)
  {
   int lca=getlca(a[i],sta[top]);
   if(lca!=sta[top])
   {
    while(dfn[lca]<dfn[sta[top-1]])
    {
     int u=sta[top-1],v=sta[top];
     getlca(u,v);
     t2.addedge(u,v,d);
     top--;
    }
    if(dfn[lca]>dfn[sta[top-1]])
    {
     getlca(lca,sta[top]);
     t2.head[lca]=0;
     t2.addedge(lca,sta[top],d);
     top--;
     sta[++top]=lca;
    }
    else
    {
     int u=sta[top-1],v=sta[top];
     getlca(u,v);
     t2.addedge(u,v,d);
     top--;
    }
   }
   t2.head[a[i]]=0;
   sta[++top]=a[i];
  }
  while(top>1)
  {
   int u=sta[top-1],v=sta[top];
   getlca(u,v);
   t2.addedge(u,v,d);
   top--;
  }
  dfs2(1);
  cout<<f[1]<<endl;
 }
 return 0;
}