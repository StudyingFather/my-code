#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 998244353
using namespace std;
struct query
{
 int r,z,id;
 bool operator<(const query&a)const
 {
  return r<a.r;
 }
};
struct seg
{
 long long sum,tag,ds;
}s[200005];
struct edge
{
 int v,next;
}e[50005];
vector<query> q;
int n,Q,k;
int head[50005],ans[50005];
int siz[50005],dep[50005],son[50005],fa[50005],num[50005];
int id[50005],top[50005],cnt;
int dk[50005];
long long fpow(long long x,long long y)
{
 long long ans=1;
 while(y)
 {
  if(y&1)ans=ans*x%MOD;
  x=x*x%MOD;
  y>>=1;
 }
 return ans;
}
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
 num[cnt]=u;
 top[u]=t;
 if(!son[u])return;
 dfs2(son[u],t);
 for(int i=head[u];i;i=e[i].next)
  if(e[i].v!=son[u])dfs2(e[i].v,e[i].v);
}
void pushup(int root)
{
 s[root].sum=(s[root<<1].sum+s[root<<1|1].sum)%MOD;
 s[root].ds=(s[root<<1].ds+s[root<<1|1].ds)%MOD;
}
void build(int root,int l,int r)
{
 if(l==r)
 {
  s[root].ds=dk[num[l]];
  return;
 }
 int mid=(l+r)>>1;
 build(root<<1,l,mid);
 build(root<<1|1,mid+1,r);
 pushup(root);
}
void pushdown(int root)
{
 s[root<<1].tag+=s[root].tag;s[root<<1].tag%=MOD;
 s[root<<1|1].tag+=s[root].tag;s[root<<1|1].tag%=MOD;
 s[root<<1].sum+=s[root].tag*s[root<<1].ds%MOD;s[root<<1].sum%=MOD;
 s[root<<1|1].sum+=s[root].tag*s[root<<1|1].ds%MOD;s[root<<1|1].sum%=MOD;
 s[root].tag=0;
}
void update(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return;
 if(l<=cl&&cr<=r)
 {
  s[root].tag++;
  s[root].sum=(s[root].sum+s[root].ds)%MOD;
  return;
 }
 pushdown(root);
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r);
 update(root<<1|1,mid+1,cr,l,r);
 pushup(root);
}
int query(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return 0;
 if(l<=cl&&cr<=r)return s[root].sum;
 pushdown(root);
 int mid=(cl+cr)>>1;
 return (query(root<<1,cl,mid,l,r)+query(root<<1|1,mid+1,cr,l,r))%MOD;
}
void update_chain(int x,int y)
{
 while(top[x]!=top[y])
 {
  if(dep[top[x]]<dep[top[y]])swap(x,y);
  update(1,1,n,id[top[x]],id[x]);
  x=fa[top[x]];
 }
 if(dep[x]>dep[y])swap(x,y);
 update(1,1,n,id[x],id[y]);
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
 ios::sync_with_stdio(false);
 cin>>n>>Q>>k;
 for(int i=2;i<=n;i++)
 {
  cin>>fa[i];
  addedge(fa[i],i);
 }
 cnt=0;
 dfs1(1,1);
 dfs2(1,1);
 for(int i=1;i<=n;i++)
  dk[i]=(fpow(dep[i],k)-fpow(dep[i]-1,k)+MOD)%MOD;
 build(1,1,n);
 for(int i=1;i<=Q;i++)
 {
  int r,z;
  cin>>r>>z;
  q.push_back({r,z,i});
 }
 sort(q.begin(),q.end());
 int u=1;
 for(auto i:q)
 {
  while(u<=i.r)
  {
   update_chain(1,u);
   u++;
  }
  ans[i.id]=query_chain(1,i.z);
 }
 for(int i=1;i<=Q;i++)
  cout<<(ans[i]+MOD)%MOD<<endl;
 return 0;
}