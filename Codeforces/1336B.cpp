#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 9e18
using namespace std;
typedef vector<int> vi;
vi a,b,c;
long long ans;
long long f(long long x,long long y,long long z)
{
 return (x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
}
void calc(vi a,vi b,vi c)
{
 for(auto p:a)
 {
  vi tb,tc;
  auto pb=lower_bound(b.begin(),b.end(),p);
  if(pb==b.end())
   pb--;
  auto pc=lower_bound(c.begin(),c.end(),p);
  if(pc==c.end())
   pc--;
  if(pb!=b.begin())
   pb--;
  if(pc!=c.begin())
   pc--;
  for(int i=1;i<=3;i++)
  {
   tb.push_back(*pb);
   pb++;
   if(pb==b.end())break;
  }
  for(int i=1;i<=3;i++)
  {
   tc.push_back(*pc);
   pc++;
   if(pc==c.end())break;
  }
  for(auto i:tb)
   for(auto j:tc)
    ans=min(ans,f(p,i,j));
 }
}
int main()
{
 ios::sync_with_stdio(false);
 int t;
 cin>>t;
 while(t--)
 {
  a.clear(),b.clear(),c.clear();
  ans=INF;
  int x,y,z;
  cin>>x>>y>>z;
  for(int i=1;i<=x;i++)
  {
   int tmp;
   cin>>tmp;
   a.push_back(tmp);
  }
  for(int i=1;i<=y;i++)
  {
   int tmp;
   cin>>tmp;
   b.push_back(tmp);
  }
  for(int i=1;i<=z;i++)
  {
   int tmp;
   cin>>tmp;
   c.push_back(tmp);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  calc(a,b,c),calc(a,c,b);
  calc(b,a,c),calc(b,c,a);
  calc(c,a,b),calc(c,b,a);
  cout<<ans<<endl;
 }
 return 0;
}