#include <iostream>
using namespace std;
long long f(long long x)
{
 return x*(x-1)/2;
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n;
  cin>>n;
  int cnt0=0,cnt2=0;
  for(int i=1;i<=n;i++)
  {
   int x;
   cin>>x;
   cnt0+=(x==0);
   cnt2+=(x==2);
  }
  cout<<f(cnt0)+f(cnt2)<<endl;
 }
 return 0;
}