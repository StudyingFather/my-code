/*
 Name: loj 2573
 Author: StudyingFather
 Date: 2019/08/09 20:30
 Website: https://studyingfather.com
*/
#include <iostream>
using namespace std;
long long s[400005],q,mod;
void pushup(int root)
{
 s[root]=s[root<<1]*s[root<<1|1]%mod;
}
void build(int root,int l,int r)
{
 if(l==r)
 {
  s[root]=1;
  return;
 }
 int mid=(l+r)>>1;
 build(root<<1,l,mid);
 build(root<<1|1,mid+1,r);
 pushup(root);
}
void update(int root,int cl,int cr,int pos,int x)
{
 if(pos<cl||cr<pos)return;
 if(cl==cr&&cl==pos)
 {
  s[root]=x;
  return;
 }
 int mid=(cl+cr)>>1;
 update(root<<1,cl,mid,pos,x);
 update(root<<1|1,mid+1,cr,pos,x);
 pushup(root);
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  cin>>q>>mod;
  build(1,1,q);
  for(int i=1;i<=q;i++)
  {
   int op,num;
   cin>>op>>num;
   if(op==1)update(1,1,q,i,num);
   else update(1,1,q,num,1);
   cout<<s[1]<<endl;
  }
 }
 return 0;
}