/*
 Name: luogu P2709
 Author: StudyingFather
 Date: 2019/08/11 08:48
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
long long a[50005],ans[50005],t[50005],res;
bool cmp(const query&a,const query&b)
{
 return a.bl<b.bl||(a.bl==b.bl&&a.br<b.br);
}
void del(int x)
{
 res-=2*t[a[x]]-1;
 t[a[x]]--;
}
void add(int x)
{
 res+=2*t[a[x]]+1;
 t[a[x]]++;
}
int main()
{
 int n,m,k;
 cin>>n>>m>>k;
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
  int ql=q[i].l,qr=q[i].r;
  while(l<ql)
  {
   del(l);
   l++;
  }
  while(l>ql)
  {
   l--;
   add(l);
  }
  while(r<qr)
  {
   r++;
   add(r);
  }
  while(r>qr)
  {
   del(r);
   r--;
  }
  ans[q[i].id]=res;
 }
 for(int i=1;i<=m;i++)
  cout<<ans[i]<<endl;
 return 0;
}