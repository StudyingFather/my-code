#include <iostream>
using namespace std;
int a[100005];
int main()
{
 long long n,ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  if(a[i]-a[i-1]>0)ans+=a[i]-a[i-1];
 }
 cout<<ans<<endl;
 return 0;
}
