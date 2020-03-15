#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
vector<int> e[200005];
int dfn[200005],top[200005],dep[200005],son[200005],fa[200005],siz[200005];
int cnt,ans1[200005],ans2[200005];
struct BIT
{
 int tr[200005],n;
 void init(int N)
 {
  n=N;
 }
 int lowbit(int x)
 {
  return x&(-x);
 }
 void add(int x,int y)
 {
  while(x<=n)
  {
   tr[x]+=y;
   x+=lowbit(x);
  }
 }
 int query(int x)
 {
  int ans=0;
  while(x)
  {
   ans+=tr[x];
   x-=lowbit(x);
  }
  return ans;
 }
 int query_sum(int x,int y)
 {
  return query(y)-query(x-1);
 }
}tr1,tr2;
struct node
{
 int id,u,v,x;
 bool operator<(const node&a)const
 {
  return x<a.x;
 }
};
queue<pii> q;
vector<node> vec;
void dfs1(int u,int f)
{
 fa[u]=f;
 dep[u]=dep[f]+1;
 siz[u]=1;
 for(auto v:e[u])
 {
  dfs1(v,u);
  if(siz[v]>siz[son[u]])
   son[u]=v;
 }
}
void dfs2(int u,int t)
{
 dfn[u]=++cnt;
 top[u]=t;
 if(!son[u])return;
 dfs2(son[u],t);
 for(auto v:e[u])
  if(v!=son[u])dfs2(v,v);
}
void query_chain(int x,int y,int id)
{
 while(top[x]!=top[y])
 {
  if(dep[top[x]]>dep[top[y]])swap(x,y);
  ans1[id]+=tr1.query_sum(dfn[top[y]],dfn[y]);
  ans2[id]+=tr2.query_sum(dfn[top[y]],dfn[y]);
  y=fa[top[y]];
 }
 if(dep[x]>dep[y])swap(x,y);
 ans1[id]+=tr1.query_sum(dfn[x],dfn[y]);
 ans2[id]+=tr2.query_sum(dfn[x],dfn[y]);
}
int main()
{
 ios::sync_with_stdio(false);
 int n,root,Q;
 cin>>n;
 tr1.init(n),tr2.init(n);
 for(int i=1;i<=n;i++)
 {
  int pa;
  cin>>pa;
  if(pa)e[pa].push_back(i);
  else root=i;
  tr1.add(i,1);
 }
 dfs1(root,0);
 dfs2(root,root);
 cin>>Q;
 for(int i=1;i<=Q;i++)
 {
  int k;
  cin>>k;
  if(k==1)
  {
   int u,v,c;
   cin>>u>>v>>c;
   vec.push_back({i,u,v,i-c});
  }
  else
  {
   int x;
   cin>>x;
   q.push(make_pair(i,x));
  }
 }
 sort(vec.begin(),vec.end());
 for(auto p:vec)
 {
  int u=p.u,v=p.v,x=p.x,id=p.id;
  while(!q.empty())
  {
   int y=q.front().first,z=q.front().second;
   if(y<x)
   {
    q.pop();
    tr2.add(dfn[z],1);
   }
   else break;
  }
  query_chain(u,v,id);
 }
 for(int i=1;i<=Q;i++)
  if(ans1[i])cout<<ans1[i]<<' '<<ans2[i]<<endl;
 return 0;
}