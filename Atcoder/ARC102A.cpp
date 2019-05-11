#include <iostream>
using namespace std;
int main()
{
 int n,k;
 cin>>n>>k;
 if(k%2)
 {
  long long ans=n/k;
  ans=ans*ans*ans;
  cout<<ans<<endl;
 }
 else
 {
  k/=2;
  long long ans=n/k;
  ans=(ans/2)*(ans/2)*(ans/2)+(ans-ans/2)*(ans-ans/2)*(ans-ans/2);
  cout<<ans<<endl;
 }
 return 0;
}