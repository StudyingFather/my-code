#include <iostream>
#include <algorithm>
using namespace std;
long long s[100005],d[100005],sum[100005];
int main()
{
 long long n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>s[i];
 sort(s+1,s+n+1);
 for(int i=1;i<n;i++)
  d[i]=s[i+1]-s[i]-1;
 sort(d+1,d+n);
 for(int i=1;i<n;i++)
  sum[i]=sum[i-1]+d[i];
 int q;
 cin>>q;
 while(q--)
 {
  long long l,r;
  cin>>l>>r;
  r-=l;
  int p=upper_bound(d,d+n,r)-d;
  cout<<n+r+sum[p-1]+(n-p)*r<<endl;
 }
 return 0;
}