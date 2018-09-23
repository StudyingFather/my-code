#include <iostream>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  long long n,total=0,a;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
   cin>>a;
   total+=a;
   total%=n;
  }
  if(!total)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
 }
 return 0;
}
