/*
 Name: Codeforces 505E
 Author: StudyingFather
 Date: 2019/10/21 23:51
 Website: https://studyingfather.com
*/
#include <iostream>
#include <queue>
using namespace std;
struct node
{
 long long d;
 int id;
 bool operator<(const node&a)const
 {
  return d>a.d;
 }
};
long long a[100005],h[100005],t[100005],n,m,k,p;
bool check(long long x)
{
 priority_queue<node> q;
 for(int i=1;i<=n;i++)
 {
  t[i]=x;
  if(x-a[i]*m<h[i])q.push({x/a[i],i});
 }
 for(int i=1;i<=m;i++)
  for(int j=1;j<=k;j++)
  {
   if(q.empty())return true;
   int d=q.top().d,id=q.top().id;
   q.pop();
   if(d<i)return false;
   t[id]+=p;
   if(t[id]-a[id]*m<h[id])q.push({t[id]/a[id],id});
  }
 return q.empty();
}
int main()
{
 cin>>n>>m>>k>>p;
 for(int i=1;i<=n;i++)
  cin>>h[i]>>a[i];
 long long l=0,r=1ll<<60;
 while(l<r)
 {
  long long mid=(l+r)>>1;
  if(check(mid))r=mid;
  else l=mid+1;
 }
 cout<<l<<endl;
 return 0;
}