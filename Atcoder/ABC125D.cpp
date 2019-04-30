#include <iostream>
#include <algorithm>
using namespace std;
long long a[100005],ans,n,cnt;
int main()
{
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  if(a[i]<=0)cnt++;
  a[i]=abs(a[i]);
 }
 sort(a+1,a+n+1);
 for(int i=2;i<=n;i++)
  ans+=a[i];
 if(cnt%2)ans-=a[1];
 else ans+=a[1];
 cout<<ans<<endl;
 return 0;
}