#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
struct node
{
 int p,h,id;
 bool operator<(const node&a)const
 {
  return p<a.p||(p==a.p&&(h<a.h||(h==a.h&&id<a.id)));
 }
}a[500005],b[500005];
set<node> s,t;
int resa[500005],resb[500005];
bool cmp(const node&a,const node&b)
{
 return a.p<b.p||(a.p==b.p&&a.h>b.h);
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i].p;
 for(int i=1;i<=n;i++)
  cin>>a[i].h;
 for(int i=1;i<=n;i++)
  a[i].id=b[i].id=i;
 for(int i=1;i<=n;i++)
  cin>>b[i].p;
 for(int i=1;i<=n;i++)
  cin>>b[i].h;
 sort(a+1,a+n+1);
 sort(b+1,b+n+1);
 for(int i=1;i<=n;i++)
 {
  if(s.empty())
  {
   int cur=i;
   while(cur<=n&&a[cur].p==a[i].p)
   {
    s.insert(a[cur]);
    cur++;
   }
  }
  if(t.empty())
  {
   int cur=i;
   while(cur<=n&&b[cur].p==b[i].p)
   {
    t.insert(b[cur]);
    cur++;
   }
  }
  if(s.size()>t.size())
  {
   node p=*t.begin();
   t.erase(p);
   p.p=(*s.begin()).p;
   resb[i]=p.id;
   p.id=n+1;
   auto it=s.upper_bound(p);
   if(it==s.end())
   {
    cout<<"impossible"<<endl;
    return 0;
   }
   resa[i]=(*it).id;
   s.erase(it);
  }
  else
  {
   node p=*s.begin();
   s.erase(p);
   p.p=(*t.begin()).p;
   resa[i]=p.id;
   p.id=0;
   auto it=t.lower_bound(p);
   if(it==t.begin())
   {
    cout<<"impossible"<<endl;
    return 0;
   }
   it--;
   resb[i]=(*it).id;
   t.erase(it);
  }
 }
 for(int i=1;i<=n;i++)
  cout<<resa[i]<<' ';
 cout<<endl;
 for(int i=1;i<=n;i++)
  cout<<resb[i]<<' ';
 cout<<endl;
 return 0;
}