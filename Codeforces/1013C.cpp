#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
long long n,a[200005];
int main()
{
 ios::sync_with_stdio(false);
 cin>>n;
 for(int i=1;i<=2*n;i++)
  cin>>a[i];
 sort(a+1,a+2*n+1);
 long long ans=(a[n]-a[1])*(a[2*n]-a[n+1]);
 for(int i=n+1;i<2*n;i++)
  ans=min((a[i]-a[i-n+1])*(a[2*n]-a[1]),ans);
 cout<<ans;
 return 0;
}
