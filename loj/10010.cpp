#include <iostream>
#include <algorithm>
using namespace std;
long long a[1000005],s[1000005];
int main()
{
 long long n,sum=0,ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  sum+=a[i];
 }
 sum/=n;
 for(int i=1;i<=n;i++)
 {
  a[i]-=sum;
  s[i]=s[i-1]+a[i];
 }
 sort(s+1,s+n+1);
 for(int i=1;i<=n;i++)
  ans+=abs(s[n/2+1]-s[i]);
 cout<<ans<<endl;
 return 0;
}