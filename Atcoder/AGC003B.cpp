#include <iostream>
using namespace std;
int main()
{
 long long n,ans=0,cur=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  if(x==0)ans+=cur/2,cur=0;
  else cur+=x;
 }
 ans+=cur/2;
 cout<<ans<<endl;
 return 0;
}