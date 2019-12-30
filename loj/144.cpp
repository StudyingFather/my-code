#include <iostream>
#include <vector>
using namespace std;
int val[1000005];
struct graph
{
 vector<int> e[1000005];
 int in[1000005],out[1000005],cnt;
 void addedge(int u,int v)
 {
  e[u].push_back(v);
 }
 void dfs(int u,int fa)
 {
  in[u]=++cnt;
  for(auto v:e[u])
   if(v!=fa)
    dfs(v,u);
  out[u]=cnt;
 }
}g;
struct BIT
{
 long long sum[1000005];
 int n;
 void init(int N,int* dfn,int* val)
 {
  n=N;
  for(int i=1;i<=n;i++)
   add(dfn[i],val[i]);
 }
 int lowbit(int x)
 {
  return x&(-x);
 }
 void add(int x,int y)
 {
  while(x<=n)
  {
   sum[x]+=y;
   x+=lowbit(x);
  }
 }
 long long query(int x)
 {
  long long ans=0;
  while(x)
  {
   ans+=sum[x];
   x-=lowbit(x);
  }
  return ans;
 }
 long long query_tree(int l,int r)
 {
  return query(r)-query(l-1);
 }
}tr;
int main()
{
 ios::sync_with_stdio(false);
 int n,m,r;
 cin>>n>>m>>r;
 for(int i=1;i<=n;i++)
  cin>>val[i];
 for(int i=1;i<n;i++)
 {
  int u,v;
  cin>>u>>v;
  g.addedge(u,v);
  g.addedge(v,u);
 }
 g.dfs(r,0);
 tr.init(n,g.in,val);
 while(m--)
 {
  int op;
  cin>>op;
  if(op==1)
  {
   int x,y;
   cin>>x>>y;
   tr.add(g.in[x],y);
  }
  else
  {
   int x;
   cin>>x;
   cout<<tr.query_tree(g.in[x],g.out[x])<<endl;
  }
 }
 return 0;
}