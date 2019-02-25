#include <iostream>
#include <algorithm>
using namespace std;
long long a[300005],ans;
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 sort(a+1,a+n+1);
 for(int i=1;i<=n/2;i++)
  ans+=(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
 cout<<ans<<endl;
 return 0;
}