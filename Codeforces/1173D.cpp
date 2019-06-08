#include <iostream>
#include <algorithm>
#define MOD 998244353
using namespace std;
int t[200005];
int main()
{
 int n;
 cin>>n;
 long long ans=n;
 for(int i=1;i<n;i++)
 {
  int u,v;
  cin>>u>>v;
  t[u]++,t[v]++;
  ans=ans*t[u]%MOD*t[v]%MOD;
 }
 cout<<ans<<endl;
 return 0;
}