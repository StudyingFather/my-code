#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000
using namespace std;
vector<int> e[100005];
int id[100005],siz[100005],son[100005],fa[100005],top[100005],dep[100005],cnt;
int x[100005],a[100005],n,q;
struct seg
{
 int ans,sum,pre,post,tag;
 seg operator+(const seg&a)const
 {
  seg res;
  res.sum=sum+a.sum;
  res.ans=max(ans,max(a.ans,post+a.pre));
  res.pre=max(pre,sum+a.pre);
  res.post=max(a.post,a.sum+post);
  res.tag=0;
  return res;
 }
}s[400005];
void dfs1(int u,int f)
{
 fa[u]=f;
 dep[u]=dep[f]+1;
 siz[u]=1;
 for(auto v:e[u])
  if(v!=f)
  {
   dfs1(v,u);
   siz[u]+=siz[v];
   if(siz[v]>siz[son[u]])
    son[u]=v;
  }
}
void dfs2(int u,int t)
{
 top[u]=t;
 id[u]=++cnt;
 a[cnt]=x[u];
 if(son[u])dfs2(son[u],t);
 for(auto v:e[u])
  if(v!=son[u]&&v!=fa[u])dfs2(v,v);
}
void pushup(int root)
{
 int tag=s[root].tag;
 s[root]=s[root<<1]+s[root<<1|1];
 s[root].tag=tag;
}
void pushdown(int root,int l,int r)
{
 if(s[root].tag!=INF)
 {
  int mid=(l+r)>>1,x=s[root].tag,ls=root<<1,rs=root<<1|1;
  s[ls].tag=s[rs].tag=x;
  s[ls].sum=(mid-l+1)*x;
  s[ls].pre=s[ls].post=s[ls].ans=max((mid-l+1)*x,0);
  s[rs].sum=(r-mid)*x;
  s[rs].pre=s[rs].post=s[rs].ans=max((r-mid)*x,0);
  s[root].tag=INF;
 }
}
void build(int root,int l,int r)
{
 if(l==r)
 {
  if(a[l]>=0)s[root]={a[l],a[l],a[l],a[l],INF};
  else s[root]={0,a[l],0,0,INF};
  return;
 }
 int mid=(l+r)>>1;
 build(root<<1,l,mid);
 build(root<<1|1,mid+1,r);
 s[root].tag=INF;
 pushup(root);
}
seg query(int root,int cl,int cr,int l,int r)
{
 if(l<=cl&&cr<=r)return s[root];
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 if(l<=mid&&mid<r)
  return query(root<<1,cl,mid,l,r)+query(root<<1|1,mid+1,cr,l,r);
 else if(l<=mid)
  return query(root<<1,cl,mid,l,r);
 else
  return query(root<<1|1,mid+1,cr,l,r);
}
void update(int root,int cl,int cr,int l,int r,int x)
{
 if(r<cl||cr<l)return;
 if(l<=cl&&cr<=r)
 {
  s[root].sum=(cr-cl+1)*x;
  s[root].tag=x;
  s[root].pre=s[root].post=s[root].ans=max(0,(cr-cl+1)*x);
  return;
 }
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r,x);
 update(root<<1|1,mid+1,cr,l,r,x);
 pushup(root);
}
seg query_chain(int x,int y)
{
 seg lans={0,0,0,0,0},rans={0,0,0,0,0};
 while(top[x]!=top[y])
 {
  if(dep[top[x]]<dep[top[y]])
  {
   rans=query(1,1,n,id[top[y]],id[y])+rans;
   y=fa[top[y]];
  }
  else
  {
   lans=query(1,1,n,id[top[x]],id[x])+lans;
   x=fa[top[x]];
  }
 }
 if(dep[x]<dep[y])
  rans=query(1,1,n,id[x],id[y])+rans;
 else
  lans=query(1,1,n,id[y],id[x])+lans;
 swap(lans.pre,lans.post);
 return lans+rans;
}
void update_chain(int x,int y,int z)
{
 while(top[x]!=top[y])
 {
  if(dep[top[x]]>dep[top[y]])swap(x,y);
  update(1,1,n,id[top[y]],id[y],z);
  y=fa[top[y]];
 }
 if(dep[x]>dep[y])swap(x,y);
 update(1,1,n,id[x],id[y],z);
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>x[i];
 for(int i=1;i<n;i++)
 {
  int u,v;
  cin>>u>>v;
  e[u].push_back(v);
  e[v].push_back(u);
 }
 dfs1(1,0);
 dfs2(1,1);
 build(1,1,n);
 cin>>q;
 while(q--)
 {
  int op;
  cin>>op;
  if(op==1)
  {
   int a,b;
   cin>>a>>b;
   cout<<query_chain(a,b).ans<<endl;
  }
  else
  {
   int a,b,c;
   cin>>a>>b>>c;
   update_chain(a,b,c);
  }
 }
 return 0;
}