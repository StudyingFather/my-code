#include <iostream>
using namespace std;
int main()
{
 long long n;
 while(cin>>n)
 {
  double num=n;
  while(num>18)
   num/=18;
  if(num<=9)cout<<"Stan wins."<<endl;
  else cout<<"Ollie wins."<<endl;
 }
 return 0;
}
