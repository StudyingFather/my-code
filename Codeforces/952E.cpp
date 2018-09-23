#include <iostream>
#include <string>
using namespace std;
string na,t;
int main()
{
 int n,ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>na>>t;
  if(na=="brie"||na=="camembert"||na=="feta"||na=="goat"||na=="muenster"||na=="asiago"||na=="cheddar"||na=="gouda"||na=="swiss")
  {
   if(t=="soft")ans--;
   else ans+=2;
  }
 }
 cout<<ans;
 return 0;
}
