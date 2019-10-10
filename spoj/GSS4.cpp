/*
 Name: SPOJ GSS4
 Author: StudyingFather
 Date: 2019/10/10 22:49
 Website: https://studyingfather.com
*/
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct seg
{
 long long sum,maxa;
}s[400005];
long long a[100005];
void pushup(int root)
{
 s[root].sum=s[root<<1].sum+s[root<<1|1].sum;
 s[root].maxa=max(s[root<<1].maxa,s[root<<1|1].maxa);
}
void build(int root,int l,int r)
{
 if(l==r)
 {
  s[root].sum=s[root].maxa=a[l];
  return;
 }
 int mid=(l+r)>>1;
 build(root<<1,l,mid);
 build(root<<1|1,mid+1,r);
 pushup(root);
}
void update(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return;
 if(s[root].maxa==1)return;
 if(cl==cr)
 {
  s[root].sum=s[root].maxa=sqrt(s[root].sum);
  return;
 }
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r);
 update(root<<1|1,mid+1,cr,l,r);
 pushup(root);
}
long long query(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return 0;
 if(l<=cl&&cr<=r)return s[root].sum;
 int mid=(cl+cr)>>1;
 return query(root<<1,cl,mid,l,r)+query(root<<1|1,mid+1,cr,l,r);
}
int main()
{
 ios::sync_with_stdio(false);
 int n,kase=0;
 while(cin>>n)
 {
  cout<<"Case #"<<++kase<<":"<<endl;
  memset(s,0,sizeof(s));
  for(int i=1;i<=n;i++)
   cin>>a[i];
  build(1,1,n);
  int m;
  cin>>m;
  while(m--)
  {
   int op,x,y;
   cin>>op>>x>>y;
   if(x>y)swap(x,y);
   if(!op)update(1,1,n,x,y);
   else cout<<query(1,1,n,x,y)<<endl;
  }
  cout<<endl;
 }
 return 0;
}