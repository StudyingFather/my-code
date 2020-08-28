// Problem: #3144. 「APIO2019」奇怪装置
// Contest: LibreOJ
// URL: https://loj.ac/problem/3144
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<long long,long long> pll;
vector<pll> v;
long long gcd(long long x,long long y)
{
 return y==0?x:gcd(y,x%y);
}
int main()
{
 ios::sync_with_stdio(false);
 long long n,a,b;
 cin>>n>>a>>b;
 long long T=a/gcd(a,b+1);
 if((__int128)T*b>=1e18)
  T=1e18;
 else
  T*=b;
 for(int i=1;i<=n;i++)
 {
  long long l,r;
  cin>>l>>r;
  if(r-l+1>=T)
  {
   cout<<T<<endl;
   return 0;
  }
  l%=T,r%=T;
  if(l<=r)
   v.emplace_back(l,r);
  else
   v.emplace_back(l,T-1),v.emplace_back(0,r);
 }
 sort(v.begin(),v.end());
 long long l=v[0].first,r=v[0].second,ans=0;
 for(auto p:v)
  if(p.first<=r)
   r=max(r,p.second);
  else
  {
   ans+=r-l+1;
   l=p.first,r=p.second;
  }
 ans+=r-l+1;
 cout<<ans<<endl;
 return 0;
}