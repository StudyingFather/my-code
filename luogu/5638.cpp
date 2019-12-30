#include <iostream>
#include <algorithm>
using namespace std;
long long sum[1000005];
int main()
{
 ios::sync_with_stdio(false);
 int n,k;
 cin>>n>>k;
 for(int i=1;i<n;i++)
 {
  long long x;
  cin>>x;
  sum[i]=sum[i-1]+x;
 }
 if(k>=n)cout<<0<<endl;
 else
 {
  long long ans=0;
  for(int i=k;i<n;i++)
   ans=max(ans,sum[i]-sum[i-k]);
  cout<<sum[n-1]-ans<<endl;
 }
 return 0;
}