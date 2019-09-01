/*
 Name: Codeforces 343D
 Author: StudyingFather
 Date: 2019/08/22 17:53
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int v,next;
}e[1000005];
struct seg
{
 int x,tag;
}s[2000005];
int head[500005],cnte,n,q;
int dep[500005],siz[500005],fa[500005],son[500005],top[500005],id[500005],cntp;
void addedge(int u,int v)
{
 e[++cnte].v=v;
 e[cnte].next=head[u];
 head[u]=cnte;
}
void dfs1(int u,int f,int d)
{
 siz[u]=1,dep[u]=d,fa[u]=f;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  if(v!=f)
  {
   dfs1(v,u,d+1);
   siz[u]+=siz[v];
   if(siz[v]>siz[son[u]])son[u]=v;
  }
 }
}
void dfs2(int u,int t)
{
 top[u]=t;
 id[u]=++cntp;
 if(!son[u])return;
 dfs2(son[u],t);
 for(int i=head[u];i;i=e[i].next)
  if(e[i].v!=son[u]&&e[i].v!=fa[u])dfs2(e[i].v,e[i].v);
}
void build(int root,int l,int r)
{
 s[root].tag=-1;
 if(l==r)return;
 int mid=(l+r)>>1;
 build(root<<1,l,mid);
 build(root<<1|1,mid+1,r);
}
void pushdown(int root)
{
 if(~s[root].tag)
 {
  s[root<<1].x=s[root<<1].tag=s[root].tag;
  s[root<<1|1].x=s[root<<1|1].tag=s[root].tag;
  s[root].tag=-1;
 }
}
void update(int root,int cl,int cr,int l,int r,int val)
{
 if(r<cl||cr<l)return;
 if(l<=cl&&cr<=r)
 {
  s[root].tag=s[root].x=val;
  return;
 }
 pushdown(root);
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r,val);
 update(root<<1|1,mid+1,cr,l,r,val);
}
void update_path(int x,int y,int val)
{
 while(top[x]!=top[y])
 {
  if(dep[top[x]]<dep[top[y]])swap(x,y);
  update(1,1,n,id[top[x]],id[x],val);
  x=fa[top[x]];
 }
 if(dep[x]>dep[y])swap(x,y);
 update(1,1,n,id[x],id[y],val);
}
int query(int root,int cl,int cr,int x)
{
 if(cr<x||x<cl)return 0;
 if(cl==cr&&cl==x)return s[root].x;
 pushdown(root);
 int mid=(cl+cr)>>1;
 return query(root<<1,cl,mid,x)+query(root<<1|1,mid+1,cr,x);
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
 dfs1(1,0,1);
 dfs2(1,1);
 build(1,1,n);
 scanf("%d",&q);
 while(q--)
 {
  int op,x;
  scanf("%d%d",&op,&x);
  if(op==1)update(1,1,n,id[x],id[x]+siz[x]-1,1);
  else if(op==2)update_path(1,x,0);
  else printf("%d\n",query(1,1,n,id[x]));
 }
 return 0;
}