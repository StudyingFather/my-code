// Problem: P4364 [九省联考2018]IIIDX
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4364
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct seg
{
 int minf,tag;
}s[2000005];
int n;
double k;
int d[500005];
int vis[500005],cnt[500005],fa[500005],siz[500005],res[500005];
vector<int> e[500005];
bool cmp(int x,int y)
{
 return x>y;
}
void dfs(int u)
{
 siz[u]=1;
 for(auto v:e[u])
  dfs(v),siz[u]+=siz[v];
}
void pushup(int root)
{
 s[root].minf=min(s[root<<1].minf,s[root<<1|1].minf);
}
void pushdown(int root)
{
 s[root<<1].minf+=s[root].tag,s[root<<1].tag+=s[root].tag;
 s[root<<1|1].minf+=s[root].tag,s[root<<1|1].tag+=s[root].tag;
 s[root].tag=0;
}
void build(int root,int l,int r)
{
 if(l==r)
 {
  s[root].minf=l;
  return;
 }
 int mid=(l+r)>>1;
 build(root<<1,l,mid);
 build(root<<1|1,mid+1,r);
 pushup(root);
}
void update(int root,int cl,int cr,int l,int r,int x)
{
 if(r<cl||cr<l)return;
 if(l<=cl&&cr<=r)
 {
  s[root].minf+=x;
  s[root].tag+=x;
  return;
 }
 pushdown(root);
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r,x);
 update(root<<1|1,mid+1,cr,l,r,x);
 pushup(root);
}
int query(int root,int l,int r,int x)
{
 if(l==r)
  return s[root].minf>=x?l:l+1;
 pushdown(root);
 int mid=(l+r)>>1;
 if(s[root<<1|1].minf<x)
  return query(root<<1|1,mid+1,r,x);
 else
  return query(root<<1,l,mid,x);
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>k;
 for(int i=1;i<=n;i++)
  cin>>d[i];
 sort(d+1,d+n+1,cmp);
 for(int i=n-1;i;i--)
  if(d[i]==d[i+1])cnt[i]=cnt[i+1]+1;
 for(int i=1;i<=n;i++)
 {
  fa[i]=i/k;
  e[fa[i]].push_back(i);
 }
 dfs(0);
 build(1,1,n);
 for(int i=1;i<=n;i++)
 {
  if(fa[i]&&!vis[fa[i]])
  {
   vis[fa[i]]=1;
   update(1,1,n,res[fa[i]],n,siz[fa[i]]-1);
  }
  int pos=query(1,1,n,siz[i]);
  pos+=cnt[pos];
  cnt[pos]++;
  res[i]=pos;
  update(1,1,n,res[i],n,-siz[i]);
 }
 for(int i=1;i<=n;i++)
  cout<<d[res[i]]<<' ';
 return 0;
}