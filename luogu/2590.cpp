#include <cstdio>
#include <algorithm>
#define INF 1000000007
using namespace std;
struct edge
{
 int v,next;
}e[60005];
struct seg
{
 int sum,maxs;
}s[120005];
int a[30005],head[30005],b[30005],cnte,cntp,n,q;
int fa[30005],dep[30005],siz[30005],son[30005],top[30005],id[30005];
char str[15];
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
 s[root].maxs=max(s[root<<1].maxs,s[root<<1|1].maxs);
}
void build(int root,int l,int r)
{
 if(l==r)
 {
  s[root].sum=s[root].maxs=b[l];
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
  s[root].sum=s[root].maxs=x;
  return;
 }
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r,x);
 update(root<<1|1,mid+1,cr,l,r,x);
 pushup(root);
}
int query_sum(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return 0;
 if(l<=cl&&cr<=r)return s[root].sum;
 int mid=(cl+cr)>>1;
 return query_sum(root<<1,cl,mid,l,r)+query_sum(root<<1|1,mid+1,cr,l,r);
}
int query_max(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return -INF;
 if(l<=cl&&cr<=r)return s[root].maxs;
 int mid=(cl+cr)>>1;
 return max(query_max(root<<1,cl,mid,l,r),query_max(root<<1|1,mid+1,cr,l,r));
}
int query_path_sum(int x,int y)
{
 int ans=0;
 while(top[x]!=top[y])
 {
  if(dep[top[x]]<dep[top[y]])swap(x,y);
  ans+=query_sum(1,1,n,id[top[x]],id[x]);
  x=fa[top[x]];
 }
 if(dep[x]>dep[y])swap(x,y);
 ans+=query_sum(1,1,n,id[x],id[y]);
 return ans;
}
int query_path_max(int x,int y)
{
 int ans=-INF;
 while(top[x]!=top[y])
 {
  if(dep[top[x]]<dep[top[y]])swap(x,y);
  ans=max(ans,query_max(1,1,n,id[top[x]],id[x]));
  x=fa[top[x]];
 }
 if(dep[x]>dep[y])swap(x,y);
 ans=max(ans,query_max(1,1,n,id[x],id[y]));
 return ans;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<n;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v);
  addedge(v,u);
 }
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 dfs1(1,0,1);
 dfs2(1,1);
 build(1,1,n);
 scanf("%d",&q);
 for(int i=1;i<=q;i++)
 {
  scanf("%s",str);
  if(str[0]=='C')
  {
   int u,t;
   scanf("%d%d",&u,&t);
   update(1,1,n,id[u],id[u],t);
  }
  else if(str[1]=='M')
  {
   int u,v;
   scanf("%d%d",&u,&v);
   printf("%d\n",query_path_max(u,v));
  }
  else
  {
   int u,v;
   scanf("%d%d",&u,&v);
   printf("%d\n",query_path_sum(u,v));
  }
 }
 return 0;
}