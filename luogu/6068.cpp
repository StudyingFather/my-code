#include <iostream>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,ans=-1;
  cin>>n;
  for(int i=1;i*i<=n;i++)
   if(n%i==0)
   {
    if(i>=6)ans=max(ans,n/i);
    if(n/i>=6)ans=max(ans,i);
   }
  cout<<ans<<endl;
 }
 return 0;
}