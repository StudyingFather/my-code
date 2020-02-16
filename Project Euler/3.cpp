#include <iostream>
using namespace std;
int main()
{
 long long num=600851475143,ans=2,maxp;
 while(ans<=num)
 {
  while(num%ans==0)num/=ans,maxp=ans;
  ans++;
 }
 cout<<maxp;
 return 0;
}
