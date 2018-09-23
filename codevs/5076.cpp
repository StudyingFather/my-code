#include <iostream>
#include <cmath>
using namespace std;
int a;
int main()
{
 cin>>a;
 if(a==1)
 {
  cout<<"no";
  return 0;
 }
 for(int i=2;i<=(int)sqrt(a);i++)
  if(a%i==0)
  {
   cout<<"no";
   return 0;
  }
 cout<<"yes";
 return 0;
}
