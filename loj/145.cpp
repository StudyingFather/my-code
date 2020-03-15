#include <cstdio>
#include <vector>
using namespace std;
struct seg
{
 long long sum,tag;
}a[4000005];
int v[1000005],p[1000005],in[1000005],out[1000005],cnt;
vector<int> e[1000005];
void pushup(int root)
{
 a[root].sum=a[root<<1].sum+a[root<<1|1].sum;
}
void pushdown(int root,int l,int r)
{
 int mid=(l+r)>>1,tag=a[root].tag;
 a[root<<1].sum+=1ll*(mid-l+1)*tag;
 a[root<<1|1].sum+=1ll*(r-mid)*tag;
 a[root<<1].tag+=tag;
 a[root<<1|1].tag+=tag;
 a[root].tag=0;
}
void build(int root,int l,int r)
{
 if(l==r)
 {
  a[root].sum=p[l];
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
  a[root].sum+=1ll*(cr-cl+1)*x;
  a[root].tag+=x;
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
 if(l<=cl&&cr<=r)return a[root].sum;
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 return query(root<<1,cl,mid,l,r)+query(root<<1|1,mid+1,cr,l,r);
}
void dfs(int u,int fa)
{
 in[u]=++cnt;
 p[cnt]=v[u];
 for(auto v:e[u])
  if(v!=fa)dfs(v,u);
 out[u]=cnt;
}
int main()
{
 //ios::sync_with_stdio(false);
 int n,m,r;
 scanf("%d%d%d",&n,&m,&r);
 for(int i=1;i<=n;i++)
  scanf("%d",&v[i]);
 for(int i=1;i<n;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  e[u].push_back(v);
  e[v].push_back(u);
 }
 dfs(r,0);
 build(1,1,n);
 while(m--)
 {
  int op;
  scanf("%d",&op);
  if(op==1)
  {
   int x,y;
   scanf("%d%d",&x,&y);
   update(1,1,n,in[x],out[x],y);
  }
  else
  {
   int x;
   scanf("%d",&x);
   printf("%lld\n",query(1,1,n,in[x],out[x]));
  }
 }
 return 0;
}