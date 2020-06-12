#include <iostream>
using namespace std;
int main()
{
 int n;
 while(cin>>n)
 {
  int b2=n*(n-1)/2,b4=n*(n-1)*(n-2)*(n-3)/24;
  cout<<1+b2+b4<<endl;
 }
 return 0;
}