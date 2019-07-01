#include <iostream>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  long long x;
  cin>>x;
  if(x==1)cout<<1<<endl;
  else cout<<x*(x-1)<<endl;
 }
 return 0;
}