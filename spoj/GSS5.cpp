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
 if(l>r)return {0,0,0,0};
 if(l<=cl&&cr<=r)return s[root];
 int mid=(cl+cr)>>1;
 if(l<=mid&&mid<r)
  return query(root<<1,cl,mid,l,r)+query(root<<1|1,mid+1,cr,l,r);
 else if(l<=mid)
  return query(root<<1,cl,mid,l,r);
 else
  return query(root<<1|1,mid+1,cr,l,r);
}
int main()
{
 ios::sync_with_stdio(false);
 int t;
 cin>>t;
 while(t--)
 {
  int n,m;
  cin>>n;
  for(int i=1;i<=n;i++)
   cin>>a[i];
  build(1,1,n);
  cin>>m;
  while(m--)
  {
   int x1,y1,x2,y2;
   cin>>x1>>y1>>x2>>y2;
   if(y1<x2)
    cout<<max(query(1,1,n,x1,y1-1).post,0)+query(1,1,n,y1,x2).sum+
          max(query(1,1,n,x2+1,y2).pre,0)<<endl;
   else
   {
    int ans1=query(1,1,n,x2,y1).ans;
    int ans2=query(1,1,n,x1,x2-1).post+query(1,1,n,x2,y1).pre;
    int ans3=query(1,1,n,x2,y1).post+query(1,1,n,y1+1,y2).pre;
    int ans4=max(query(1,1,n,x1,x2-1).post,0)+query(1,1,n,x2,y1).sum+
             max(query(1,1,n,y1+1,y2).pre,0);
    cout<<max(ans1,max(ans2,max(ans3,ans4)))<<endl;
   }
  }
 }
 return 0;
}