#include <cstdio>
#include <vector>
#include <algorithm>
#define MOD 201314
using namespace std;
struct query
{
 int l,r,z,id,op;
 bool operator<(const query&a)const
 {
  return r<a.r||(r==a.r&&l<a.l);
 }
};
struct seg
{
 int sum,tag;
}s[200005];
struct edge
{
 int v,next;
}e[50005];
vector<query> q;
int n,Q;
int head[50005],ans[50005];
int siz[50005],dep[50005],son[50005],fa[50005];
int id[50005],top[50005],cnt;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs1(int u,int f)
{
 siz[u]=1;
 dep[u]=dep[f]+1;
 for(int i=head[u];i;i=e[i].next)
 {
  int v=e[i].v;
  dfs1(v,u);
  siz[u]+=siz[v];
  if(siz[v]>siz[son[u]])son[u]=v;
 }
}
void dfs2(int u,int t)
{
 id[u]=++cnt;
 top[u]=t;
 if(!son[u])return;
 dfs2(son[u],t);
 for(int i=head[u];i;i=e[i].next)
  if(e[i].v!=son[u])dfs2(e[i].v,e[i].v);
}
void pushup(int root)
{
 s[root].sum=(s[root<<1].sum+s[root<<1|1].sum)%MOD;
}
void pushdown(int root,int l,int r)
{
 int mid=(l+r)>>1;
 s[root<<1].tag+=s[root].tag;s[root<<1].tag%=MOD;
 s[root<<1|1].tag+=s[root].tag;s[root<<1|1].tag%=MOD;
 s[root<<1].sum+=s[root].tag*(mid-l+1);s[root<<1].sum%=MOD;
 s[root<<1|1].sum+=s[root].tag*(r-mid);s[root<<1|1].sum%=MOD;
 s[root].tag=0;
}
void update(int root,int cl,int cr,int l,int r,int x)
{
 if(r<cl||cr<l)return;
 if(l<=cl&&cr<=r)
 {
  s[root].tag+=x;
  s[root].sum=(s[root].sum+(cr-cl+1)*x)%MOD;
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
 return (query(root<<1,cl,mid,l,r)+query(root<<1|1,mid+1,cr,l,r))%MOD;
}
void update_chain(int x,int y,int z)
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
int query_chain(int x,int y)
{
 int ans=0;
 while(top[x]!=top[y])
 {
  if(dep[top[x]]<dep[top[y]])swap(x,y);
  ans=(ans+query(1,1,n,id[top[x]],id[x]))%MOD;
  x=fa[top[x]];
 }
 if(dep[x]>dep[y])swap(x,y);
 ans=(ans+query(1,1,n,id[x],id[y]))%MOD;
 return ans;
}
int main()
{
 scanf("%d%d",&n,&Q);
 for(int i=2;i<=n;i++)
 {
  scanf("%d",&fa[i]);
  fa[i]++;
  addedge(fa[i],i);
 }
 cnt=0;
 dfs1(1,1);
 dfs2(1,1);
 for(int i=1;i<=Q;i++)
 {
  int l,r,z;
  scanf("%d%d%d",&l,&r,&z);
  l++,r++,z++;
  q.push_back({l,r,z,i,1});
  q.push_back({1,l-1,z,i,-1});
 }
 sort(q.begin(),q.end());
 int u=1;
 for(auto i:q)
 {
  while(u<=i.r)
  {
   update_chain(1,u,1);
   u++;
  }
  ans[i.id]+=i.op*query_chain(1,i.z);
 }
 for(int i=1;i<=Q;i++)
  printf("%d\n",(ans[i]%MOD+MOD)%MOD);
 return 0;
}