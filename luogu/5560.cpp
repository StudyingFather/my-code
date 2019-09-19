#include <iostream>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  long long n;
  cin>>n;
  if(n==4||n==10)cout<<n+1<<endl;
  else cout<<n-1<<endl;
 }
 return 0;
}