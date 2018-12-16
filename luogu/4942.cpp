#include <iostream>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  long long l,r;
  cin>>l>>r;
  cout<<((l+r)%9*(r-l+1)%9*5)%9<<endl;
 }
 return 0;
}
