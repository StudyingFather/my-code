#include <iostream>
using namespace std;
long long a,ans;
int main()
{
 ios::sync_with_stdio(false);
 for(int i=1;i<=3000000;i++)
 {
  cin>>a;
  ans^=a;
 }
 cout<<ans;
 return 0;
}
