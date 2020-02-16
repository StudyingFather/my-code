#include <iostream>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,k;
  long long sum=0;
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
   int x;
   cin>>x;
   sum+=x;
  }
  cout<<sum%k<<endl;
 }
 return 0;
}