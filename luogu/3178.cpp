#include <iostream>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[200005];
struct seg
{
 long long sum,tag;
}s[400005];
int a[100005],b[100005],head[100005],n,m,cnte;
int fa[100005],dep[100005],son[100005],siz[100005],id[100005],top[100005],cntp;
void addedge(int u,int v)
{
 e[++cnte].v=v;
 e[cnte].next=head[u];
 head[u]=cnte;
}
void dfs1(int u,int f,int d)
{
 fa[u]=f;
 dep[u]=d;
 siz[u]=1;
 for(int i=head[u];i;i=e[i].next)
  if(e[i].v!=f)
  {
   dfs1(e[i].v,u,d+1);
   siz[u]+=siz[e[i].v];
   if(siz[e[i].v]>siz[son[u]])son[u]=e[i].v;
  }
}
void dfs2(int u,int t)
{
 top[u]=t;
 id[u]=++cntp;
 b[cntp]=a[u];
 if(!son[u])return;
 dfs2(son[u],t);
 for(int i=head[u];i;i=e[i].next)
  if(e[i].v!=fa[u]&&e[i].v!=son[u])dfs2(e[i].v,e[i].v);
}
void pushup(int root)
{
 s[root].sum=s[root<<1].sum+s[root<<1|1].sum;
}
void pushdown(int root,int l,int r)
{
 int mid=(l+r)>>1;
 s[root<<1].tag+=s[root].tag;
 s[root<<1|1].tag+=s[root].tag;
 s[root<<1].sum+=s[root].tag*(long long)(mid-l+1);
 s[root<<1|1].sum+=s[root].tag*(long long)(r-mid);
 s[root].tag=0;
}
void build(int root,int l,int r)
{
 if(l==r)
 {
  s[root].sum=b[l];
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
  s[root].sum+=(long long)(cr-cl+1)*x;
  s[root].tag+=x;
  return;
 }
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r,x);
 update(root<<1|1,mid+1,cr,l,r,x);
 pushup(root);
}
long long query(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return 0;
 if(l<=cl&&cr<=r)return s[root].sum;
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 return query(root<<1,cl,mid,l,r)+query(root<<1|1,mid+1,cr,l,r);
}
long long query_path(int x,int y)
{
 long long ans=0;
 while(top[x]!=top[y])
 {
  if(dep[top[x]]<dep[top[y]])swap(x,y);
  ans+=query(1,1,n,id[top[x]],id[x]);
  x=fa[top[x]];
 }
 if(dep[x]>dep[y])swap(x,y);
 ans+=query(1,1,n,id[x],id[y]);
 return ans;
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=1;i<n;i++)
 {
  int u,v;
  cin>>u>>v;
  addedge(u,v);
  addedge(v,u);
 }
 dfs1(1,0,1);
 dfs2(1,1);
 build(1,1,n);
 for(int i=1;i<=m;i++)
 {
  int op,x,y;
  cin>>op;
  if(op==1)
  {
   cin>>x>>y;
   update(1,1,n,id[x],id[x],y);
  }
  else if(op==2)
  {
   cin>>x>>y;
   update(1,1,n,id[x],id[x]+siz[x]-1,y);
  }
  else
  {
   cin>>x;
   cout<<query_path(1,x)<<endl;
  }
 }
 return 0;
}