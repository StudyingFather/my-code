#include <iostream>
using namespace std;
struct operation
{
 int op,l,r;
}p[100005];
struct seg
{
 int sum,tag;
}s[400005];
int a[100005],n,m,q;
void pushup(int root)
{
 s[root].sum=s[root<<1].sum+s[root<<1|1].sum;
}
void pushdown(int root,int l,int r)
{
 if(s[root].tag!=-1)
 {
  int tag=s[root].tag,ls=root<<1,rs=root<<1|1,mid=(l+r)>>1;
  s[ls].sum=(mid-l+1)*tag;
  s[rs].sum=(r-mid)*tag;
  s[ls].tag=s[rs].tag=tag;
  s[root].tag=-1;
 }
}
void build(int root,int l,int r,int x)
{
 s[root].tag=-1;
 if(l==r)
 {
  s[root].sum=(a[l]>=x);
  return;
 }
 int mid=(l+r)>>1;
 build(root<<1,l,mid,x);
 build(root<<1|1,mid+1,r,x);
 pushup(root);
}
void update(int root,int cl,int cr,int l,int r,int x)
{
 if(r<cl||cr<l)return;
 if(l<=cl&&cr<=r)
 {
  s[root].sum=(cr-cl+1)*x;
  s[root].tag=x;
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
bool check(int x)
{
 build(1,1,n,x);
 for(int i=1;i<=m;i++)
 {
  int op=p[i].op,l=p[i].l,r=p[i].r;
  int cnt=query(1,1,n,l,r);
  if(op)
   update(1,1,n,l,l+cnt-1,1),update(1,1,n,l+cnt,r,0);
  else
   update(1,1,n,l,r-cnt,0),update(1,1,n,r-cnt+1,r,1);
 }
 return query(1,1,n,q,q);
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=1;i<=m;i++)
  cin>>p[i].op>>p[i].l>>p[i].r;
 cin>>q;
 int l=1,r=n,ans;
 while(l<=r)
 {
  int mid=(l+r)>>1;
  if(check(mid))ans=mid,l=mid+1;
  else r=mid-1;
 }
 cout<<ans<<endl;
 return 0;
}