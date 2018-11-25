#include <iostream>
#include <algorithm>
using namespace std;
long long a[1000005],ans;
int main()
{
 ios::sync_with_stdio(false);
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  if(i!=1)ans+=max(a[i],a[i-1]);
 }
 cout<<ans<<endl;
 return 0;
}
