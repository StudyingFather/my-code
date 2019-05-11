#include <iostream>
#include <algorithm>
using namespace std;
struct Segment_Tree
{
 long long v,add,mul;
}tr[400005];
long long a[100005];
long long n,m,p;
void pushup(int x)
{
 tr[x].v=(tr[x<<1].v+tr[x<<1|1].v)%p;
}
void build(int root,int l,int r)
{
 tr[root].mul=1;
 tr[root].add=0;
 if(l==r)tr[root].v=a[l];
 else
 {
  int mid=(l+r)>>1;
  build(root<<1,l,mid);
  build(root<<1|1,mid+1,r);
  pushup(root);
 }
 return;
}
void pushdown(int root,int l,int r)
{
 int mid=(l+r)>>1;
 tr[root<<1].v=(tr[root<<1].v*tr[root].mul+tr[root].add*(mid-l+1))%p;
 tr[root<<1|1].v=(tr[root<<1|1].v*tr[root].mul+tr[root].add*(r-mid))%p;
 tr[root<<1].mul=(tr[root<<1].mul*tr[root].mul)%p;
 tr[root<<1|1].mul=(tr[root<<1|1].mul*tr[root].mul)%p;
 tr[root<<1].add=(tr[root<<1].add*tr[root].mul+tr[root].add)%p;
 tr[root<<1|1].add=(tr[root<<1|1].add*tr[root].mul+tr[root].add)%p;
 tr[root].mul=1;
 tr[root].add=0;
 return;
}
void update1(int root,int cl,int cr,int l,int r,long long k)
{
 if(r<cl||cr<l)return;
 if(l<=cl&&cr<=r)
 {
  tr[root].v=(tr[root].v*k)%p;
  tr[root].mul=(tr[root].mul*k)%p;
  tr[root].add=(tr[root].add*k)%p;
  return;
 }
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 update1(root<<1,cl,mid,l,r,k);
 update1(root<<1|1,mid+1,cr,l,r,k);
 pushup(root);
 return;
}
void update2(int root,int cl,int cr,int l,int r,long long k)
{
 if(r<cl||cr<l)return;
 if(l<=cl&&cr<=r)
 {
  tr[root].add=(tr[root].add+k)%p;
  tr[root].v=(tr[root].v+k*(cr-cl+1))%p;
  return;
 }
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 update2(root<<1,cl,mid,l,r,k);
 update2(root<<1|1,mid+1,cr,l,r,k);
 pushup(root);
 return;
}
long long query(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return 0;
 if(l<=cl&&cr<=r)return tr[root].v;
 pushdown(root,cl,cr);
 int mid=(cl+cr)>>1;
 return (query(root<<1,cl,mid,l,r)+query(root<<1|1,mid+1,cr,l,r))%p;
}
int main()
{
 cin>>n>>p;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 build(1,1,n);
 cin>>m;
 for(int i=1;i<=m;i++)
 {
  int op;
  cin>>op;
  if(op==1)
  {
   int x,y,k;
   cin>>x>>y>>k;
   update1(1,1,n,x,y,k);
  }
  else if(op==2)
  {
   int x,y,k;
   cin>>x>>y>>k;
   update2(1,1,n,x,y,k);
  }
  else
  {
   int x,y;
   cin>>x>>y;
   cout<<query(1,1,n,x,y)<<endl;
  }
 }
 return 0;
}