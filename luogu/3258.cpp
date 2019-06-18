#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[600005];
struct seg
{
 int sum,tag;
}s[1200005];
int a[300005],head[300005],n,cnte,cntp;
int fa[300005],dep[300005],son[300005],siz[300005],top[300005],id[300005];
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
 s[root<<1].sum+=s[root].tag*(mid-l+1);
 s[root<<1|1].sum+=s[root].tag*(r-mid);
 s[root].tag=0;
}
void update(int root,int cl,int cr,int l,int r,int x)
{
 if(r<cl||cr<l)return;
 if(l<=cl&&cr<=r)
 {
  s[root].sum+=x*(cr-cl+1);
  s[root].tag+=x;
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
 return query(root<<1,cl,mid,l,r)+query(root<<1|1,mid+1,cr,l,r);
}
void update_path(int x,int y)
{
 while(top[x]!=top[y])
 {
  if(dep[top[x]]<dep[top[y]])swap(x,y);
  update(1,1,n,id[top[x]],id[x],1);
  x=fa[top[x]];
 }
 if(dep[x]>dep[y])swap(x,y);
 update(1,1,n,id[x],id[y],1);
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<n;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v);
  addedge(v,u);
 }
 dfs1(1,0,1);
 dfs2(1,1);
 for(int i=1;i<n;i++)
 {
  update_path(a[i],a[i+1]);
  update(1,1,n,id[a[i+1]],id[a[i+1]],-1);
 }
 for(int i=1;i<=n;i++)
  printf("%d\n",query(1,1,n,id[i],id[i]));
 return 0;
}