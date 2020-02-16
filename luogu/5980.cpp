#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
 ios::sync_with_stdio(false);
 int t;
 cin>>t;
 while(t--)
 {
  vector<pair<int,int> > a,b;
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
   int l,x,y;
   cin>>l>>x>>y;
   a.push_back({x,l});
   b.push_back({y,l});
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int p=0,q=0;
  long long sum=0;
  bool flag=true;
  while(p<n)
  {
   int l=min(a[p].second,b[q].second);
   sum-=1ll*l*(a[p].first-b[q].first);
   if(sum<0)
   {
    flag=false;
    break;
   }
   a[p].second-=l,b[q].second-=l;
   if(a[p].second==0)p++;
   if(b[q].second==0)q++;
  }
  if(flag&&sum==0)cout<<"TAK"<<endl;
  else cout<<"NIE"<<endl;
 }
 return 0;
}