#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[200005];
struct seg
{
 int sum,tag;
}s[400005];
int a[100005],head[100005],b[100005],cnte,cntp;
int fa[100005],dep[100005],siz[100005],son[100005],top[100005],id[100005];
int n,m,r,p;
void pushup(int root)
{
 s[root].sum=(s[root<<1].sum+s[root<<1|1].sum)%p;
}
void pushdown(int root,int l,int r)
{
 int mid=(l+r)>>1;
 s[root<<1].tag=(s[root<<1].tag+s[root].tag)%p;
 s[root<<1|1].tag=(s[root<<1|1].tag+s[root].tag)%p;
 s[root<<1].sum=(s[root<<1].sum+s[root].tag*(mid-l+1))%p;
 s[root<<1|1].sum=(s[root<<1|1].sum+s[root].tag*(r-mid))%p;
 s[root].tag=0;
}
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
void build(int root,int l,int r)
{
 if(l==r)
 {
  s[root].sum=b[l]%p;
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
  s[root].tag+=x;
  s[root].sum=(s[root].sum+(cr-cl+1)*x)%p;
  return;
 }
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r,x);
 update(root<<1|1,mid+1,cr,l,r,x);
 pushup(root);
}
int query(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return 0;
 if(l<=cl&&cr<=r)return s[root].sum;
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 return (query(root<<1,cl,mid,l,r)+query(root<<1|1,mid+1,cr,l,r))%p;
}
void update_path(int x,int y,int z)
{
 while(top[x]!=top[y])
 {
  if(dep[top[x]]<dep[top[y]])swap(x,y);
  update(1,1,n,id[top[x]],id[x],z);
  x=fa[top[x]];
 }
 if(dep[x]>dep[y])swap(x,y);
 update(1,1,n,id[x],id[y],z);
}
int query_path(int x,int y)
{
 int ans=0;
 while(top[x]!=top[y])
 {
  if(dep[top[x]]<dep[top[y]])swap(x,y);
  ans=(ans+query(1,1,n,id[top[x]],id[x]))%p;
  x=fa[top[x]];
 }
 if(dep[x]>dep[y])swap(x,y);
 ans=(ans+query(1,1,n,id[x],id[y]))%p;
 return ans;
}
int main()
{
 scanf("%d%d%d%d",&n,&m,&r,&p);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<n;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v);
  addedge(v,u);
 }
 dfs1(r,0,1);
 dfs2(r,r);
 build(1,1,n);
 for(int i=1;i<=m;i++)
 {
  int op,x,y,z;
  scanf("%d",&op);
  if(op==1)
  {
   scanf("%d%d%d",&x,&y,&z);
   update_path(x,y,z%p);
  }
  else if(op==2)
  {
   scanf("%d%d",&x,&y);
   printf("%d\n",query_path(x,y));
  }
  else if(op==3)
  {
   scanf("%d%d",&x,&z);
   update(1,1,n,id[x],id[x]+siz[x]-1,z%p);
  }
  else
  {
   scanf("%d",&x);
   printf("%d\n",query(1,1,n,id[x],id[x]+siz[x]-1));
  }
 }
 return 0;
}