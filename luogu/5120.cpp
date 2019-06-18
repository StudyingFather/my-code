#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <queue>
#include <map>
using namespace std;
struct node
{
 long long id,a,t;
 bool operator<(const node&a)const
 {
  return a.id<id;
 }
}a[100005];
struct lian
{
 long long t;
 vector<int> l;
}b[100005];
priority_queue<node> q;
map<int,int> ma;
bool cmp(const node&a,const node&b)
{
 return a.a<b.a||(a.a==b.a&&a.id<b.id);
}
int main()
{
 long long n,ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i].a>>a[i].t;
  a[i].id=i;
 }
 sort(a+1,a+n+1,cmp);
 long long x=a[1].a,cnt=1;
 b[1].t=x;
 ma[1]=x;
 for(int i=1;i<=n;i++)
  if(a[i].a==x)b[cnt].l.push_back(i);
  else
  {
   b[++cnt].t=a[i].a;
   ma[cnt]=a[i].a;
   b[cnt].l.push_back(i);
  }
 long long curt=a[1].a,curl=b[1].t,inque=0,pi=1;
 for(vector<int>::iterator it=b[1].l.begin();it!=b[1].l.end();it++)
  q.push(a[*it]),inque++;
 while(!q.empty())
 {
  node eatc=q.top();
  ans=max(ans,curt-eatc.a);
  curt+=eatc.t;
  q.pop();
  while(ma[pi+1]<=curt&&ma[pi+1]!=0)
  {
   for(vector<int>::iterator it=b[++pi].l.begin();it!=b[pi].l.end();it++)
    q.push(a[*it]),inque++;
   curl=ma[pi];
   if(curl==0)break;
  }
  if(q.empty()&&inque<n)
  {
   for(vector<int>::iterator it=b[++pi].l.begin();it!=b[pi].l.end();it++)
    q.push(a[*it]),inque++;
   curl=ma[pi];
   curt=max(a[inque].a,curt);
  }
 }
 cout<<ans<<endl;
 return 0;
}