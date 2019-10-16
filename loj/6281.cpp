/*
 Name: loj 6281
 Author: StudyingFather
 Date: 2019/10/16 08:26
 Website: https://studyingfather.com
*/
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
struct seg
{
 long long sum,max;
}s[400005];
long long a[100005];
void pushup(int root)
{
 s[root].sum=s[root<<1].sum+s[root<<1|1].sum;
 s[root].max=max(s[root<<1].max,s[root<<1|1].max);
}
void build(int root,int l,int r)
{
 if(l==r)
 {
  s[root].sum=s[root].max=a[l];
  return;
 }
 int mid=(l+r)>>1;
 build(root<<1,l,mid);
 build(root<<1|1,mid+1,r);
 pushup(root);
}
long long query(int root,int cl,int cr,int l,int r)
{
 if(r<cl||cr<l)return 0;
 if(l<=cl&&cr<=r)return s[root].sum;
 int mid=(cl+cr)>>1;
 return query(root<<1,cl,mid,l,r)+query(root<<1|1,mid+1,cr,l,r);
}
void update(int root,int cl,int cr,int l,int r)
{
 if(s[root].max==1)return;
 if(r<cl||cr<l)return;
 if(cl==cr)
 {
  s[root].sum=s[root].max=sqrt(s[root].sum);
  return;
 }
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,l,r);
 update(root<<1|1,mid+1,cr,l,r);
 pushup(root);
}
int main()
{
 int n,m;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 build(1,1,n);
 for(int i=1;i<=n;i++)
 {
  int op,l,r,c;
  cin>>op>>l>>r>>c;
  if(op)cout<<query(1,1,n,l,r)<<endl;
  else update(1,1,n,l,r);
 }
 return 0;
}