#include <iostream>
#include <vector>
using namespace std;
struct seg
{
 long long sum,tag;
}s[400005];
vector<int> e[100005];
int dep[100005],son[100005],fa[100005],siz[100005];
int top[100005],id[100005],cnt;
int n,q;
void dfs1(int u,int f)
{
 fa[u]=f;
 dep[u]=dep[f]+1;
 siz[u]=1;
 for(auto v:e[u])
 {
  dfs1(v,u);
  siz[u]+=siz[v];
  if(siz[v]>siz[son[u]])
   son[u]=v;
 }
}
void dfs2(int u,int t)
{
 id[u]=++cnt;
 top[u]=t;
 if(!son[u])return;
 dfs2(son[u],t);
 for(auto v:e[u])
  if(v!=son[u])dfs2(v,v);
}
void pushup(int root)
{
 s[root].sum=s[root<<1].sum+s[root<<1|1].sum;
}
void pushdown(int root,int l,int r)
{
 long long tag=s[root].tag;
 int mid=(l+r)>>1;
 s[root<<1].tag+=tag;
 s[root<<1|1].tag+=tag;
 s[root<<1].sum+=tag*(mid-l+1);
 s[root<<1|1].sum+=tag*(r-mid);
 s[root].tag=0;
}
void update(int root,int cl,int cr,int l,int r,int x)
{
 if(r<cl||cr<l)return;
 if(l<=cl&&cr<=r)
 {
  s[root].sum+=1ll*(cr-cl+1)*x;
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
void update_chain(int u,int v,int w)
{
 while(top[u]!=top[v])
 {
  if(dep[top[u]]>dep[top[v]])swap(u,v);
  update(1,1,n,id[top[v]],id[v],w);
  v=fa[top[v]];
 }
 if(dep[u]>dep[v])swap(u,v);
 update(1,1,n,id[u],id[v],w);
}
int main()
{
 cin>>n;
 for(int i=1;i<n;i++)
 {
  int u,v;
  cin>>u>>v;
  u++,v++;
  e[u].push_back(v);
 }
 dfs1(1,0);
 dfs2(1,1);
 cin>>q;
 while(q--)
 {
  string op;
  cin>>op;
  if(op=="A")
  {
   int u,v,d;
   cin>>u>>v>>d;
   u++,v++;
   update_chain(u,v,d);
  }
  else
  {
   int u;
   cin>>u;
   u++;
   cout<<query(1,1,n,id[u],id[u]+siz[u]-1)<<endl;
  }
 }
 return 0;
}