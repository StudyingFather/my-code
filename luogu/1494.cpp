/*
 Name: luogu P1494
 Author: StudyingFather
 Date: 2019/08/17 15:58
 Website: https://studyingfather.com
*/
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
struct query
{
 int l,r,bl,br,id;
}q[50005];
long long a[50005],t[50005],ans1[50005],ans2[50005],num1;
bool cmp(const query&a,const query&b)
{
 return a.bl<b.bl||(a.bl==b.bl&&a.br<b.br);
}
long long gcd(long long x,long long y)
{
 return y==0?x:gcd(y,x%y);
}
void add(int x)
{
 num1+=t[x]*2;
 t[x]++;
}
void del(int x)
{
 t[x]--;
 num1-=t[x]*2;
}
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 int siz=sqrt(n);
 for(int i=1;i<=m;i++)
 {
  cin>>q[i].l>>q[i].r;
  q[i].bl=(q[i].l-1)/siz+1;
  q[i].br=(q[i].r-1)/siz+1;
  q[i].id=i;
 }
 sort(q+1,q+m+1,cmp);
 int l=1,r=0;
 for(int i=1;i<=m;i++)
 {
  long long ql=q[i].l,qr=q[i].r;
  while(l<ql)
  {
   del(a[l]);
   l++;
  }
  while(l>ql)
  {
   l--;
   add(a[l]);
  }
  while(r<qr)
  {
   r++;
   add(a[r]);
  }
  while(r>qr)
  {
   del(a[r]);
   r--;
  }
  if(ql==qr)
   ans1[q[i].id]=0,ans2[q[i].id]=1;
  else
  {
   int tmp=gcd(num1,(qr-ql+1)*(qr-ql));
   ans1[q[i].id]=num1/tmp;
   ans2[q[i].id]=(qr-ql+1)*(qr-ql)/tmp;
  }
 }
 for(int i=1;i<=m;i++)
  cout<<ans1[i]<<'/'<<ans2[i]<<endl;
 return 0;
}