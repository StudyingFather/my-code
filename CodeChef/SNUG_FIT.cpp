#include <iostream>
#include <algorithm>
using namespace std;
int a[10005],b[10005];
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n;
  long long ans=0;
  cin>>n;
  for(int i=1;i<=n;i++)
   cin>>a[i];
  for(int i=1;i<=n;i++)
   cin>>b[i];
  sort(a+1,a+n+1);
  sort(b+1,b+n+1);
  for(int i=1;i<=n;i++)
   ans+=min(a[i],b[i]);
  cout<<ans<<endl;
 }
 return 0;
}