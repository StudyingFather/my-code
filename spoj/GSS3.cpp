#include <iostream>
using namespace std;
struct seg
{
 int ans,sum,pre,post;
 seg operator+(const seg&a)const
 {
  seg res;
  res.sum=sum+a.sum;
  res.ans=max(ans,max(a.ans,post+a.pre));
  res.pre=max(pre,sum+a.pre);
  res.post=max(a.post,a.sum+post);
  return res;
 }
}s[200005];
int a[50005];
void pushup(int root)
{
 s[root]=s[root<<1]+s[root<<1|1];
}
void build(int root,int l,int r)
{
 if(l==r)
 {
  s[root]={a[l],a[l],a[l],a[l]};
  return;
 }
 int mid=(l+r)>>1;
 build(root<<1,l,mid);
 build(root<<1|1,mid+1,r);
 pushup(root);
}
seg query(int root,int cl,int cr,int l,int r)
{
 if(l<=cl&&cr<=r)return s[root];
 int mid=(cl+cr)>>1;
 if(l<=mid&&mid<r)
  return query(root<<1,cl,mid,l,r)+query(root<<1|1,mid+1,cr,l,r);
 else if(l<=mid)
  return query(root<<1,cl,mid,l,r);
 else
  return query(root<<1|1,mid+1,cr,l,r);
}
void update(int root,int cl,int cr,int pos,int x)
{
 if(cr<pos||pos<cl)return;
 if(cl==cr)
 {
  s[root]={x,x,x,x};
  return;
 }
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,pos,x);
 update(root<<1|1,mid+1,cr,pos,x);
 pushup(root);
}
int main()
{
 ios::sync_with_stdio(false);
 int n,m;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 build(1,1,n);
 cin>>m;
 while(m--)
 {
  int op,x,y;
  cin>>op>>x>>y;
  if(op==0)update(1,1,n,x,y);
  if(op==1)cout<<query(1,1,n,x,y).ans<<endl;
 }
 return 0;
}