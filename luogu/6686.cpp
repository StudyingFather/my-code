// Problem: P6686 混凝土数学
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6686
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#define MOD 998244353
using namespace std;
long long a[200005],b[200005];
int main()
{
 ios::sync_with_stdio(false);
 int n,maxa=0;
 long long ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  a[x]++;
  maxa=max(maxa,x);
 }
 for(int i=1;i<=maxa;i++)
  b[i]=b[i-1]+a[i];
 for(int i=1;i<=maxa;i++)
  if(a[i]>=2)
  {
   ans=(ans+(a[i]*(a[i]-1)/2)%MOD*(b[min(maxa,2*i-1)]-a[i]))%MOD;
   ans=(ans+(a[i]*(a[i]-1)*(a[i]-2)/6)%MOD)%MOD;
  }
 cout<<ans<<endl;
 return 0;
}