
// Problem : E - Smart Infants
// Contest : AtCoder - AtCoder Beginner Contest 170
// URL : https://atcoder.jp/contests/abc170/tasks/abc170_e
// Memory Limit : 1024 MB
// Time Limit : 3500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <set>
using namespace std;
struct node
{
 int id,x;
 bool operator<(const node&a)const
 {
  return x<a.x||(x==a.x&&id<a.id);
 }
 bool operator==(const node&a)const
 {
  return id==a.id&&x==a.x;
 }
 bool operator>(const node&a)const
 {
  return x>a.x||(x==a.x&&id>a.id);
 }
};
set<node,greater<node> > s[200005];
set<node> res;
int a[200005],b[200005];
int maxa[200005];
int main()
{
 ios::sync_with_stdio(false);
 int n,q;
 cin>>n>>q;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i]>>b[i];
  s[b[i]].insert({i,a[i]});
 }
 for(int i=1;i<=200000;i++)
  if(!s[i].empty())
  {
   maxa[i]=(*s[i].begin()).x;
   res.insert({i,maxa[i]});
  }
 while(q--)
 {
  int c,d;
  cin>>c>>d;
  auto it=s[b[c]].lower_bound({c,a[c]});
  s[d].insert(*it);
  s[b[c]].erase(it);
  auto it2=res.lower_bound({b[c],maxa[b[c]]});
  res.erase(it2);
  if(s[d].size()>1)
  {
   it2=res.lower_bound({d,maxa[d]});
   res.erase(it2);
  }
  if(s[b[c]].empty())
   maxa[b[c]]=0;
  else
   maxa[b[c]]=(*s[b[c]].begin()).x;
  maxa[d]=(*s[d].begin()).x;
  if(!s[b[c]].empty())
   res.insert({b[c],maxa[b[c]]});
  res.insert({d,maxa[d]});
  cout<<(*res.begin()).x<<endl;
  b[c]=d;
 }
 return 0;
}