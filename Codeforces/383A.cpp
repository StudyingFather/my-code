#include <iostream>
using namespace std;
int main()
{
 long long n,cnt=0,ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int a;
  cin>>a;
  if(a)cnt++;
  else ans+=cnt;
 }
 cout<<ans;
 return 0;
}
