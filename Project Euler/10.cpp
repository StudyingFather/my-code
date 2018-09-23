#include <iostream>
using namespace std;
bool is_prime(int num)
{
 if(num==1)return false;
 for(int i=2;i*i<=num;i++)
  if(num%i==0)return false;
 return true;
}
int main()
{
 long long ans=0;
 for(int i=2;i<=2000000;i++)
  if(is_prime(i))ans+=i;
 cout<<ans;
 return 0;
}
