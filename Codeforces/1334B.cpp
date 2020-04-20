#include <iostream>
#include <set>
using namespace std;
multiset<int> s;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  s.clear();
  int n,p,ans=0;
  long long tot=0;
  cin>>n>>p;
  for(int i=1;i<=n;i++)
  {
   int x;
   cin>>x;
   if(x>=p)tot+=(x-p),ans++;
   else s.insert(p-x);
  }
  while(!s.empty())
  {
   int x=*s.begin();
   s.erase(s.begin());
   if(tot>=x)tot-=x,ans++;
   else break;
  }
  cout<<ans<<endl;
 }
 return 0;
}