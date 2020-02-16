#include <iostream>
#include <algorithm>
using namespace std;
long long a[100005],s[100005],ans;
int main()
{
 ios::sync_with_stdio(false);
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 sort(a+1,a+n+1);
 for(int i=1;i<=n;i++)
 {
  s[i]=s[i-1]+a[i];
  ans+=a[i]*(i-1)-s[i-1];
 }
 cout<<ans*2<<endl;
 return 0;
}