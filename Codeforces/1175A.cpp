#include <iostream>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  long long n,k,ans=0;
  while(n)
  {
   ans+=n%k;
   n/=k;
   ans++;
  }
  cout<<ans-1<<endl;
 }
 return 0;
}