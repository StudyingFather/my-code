#include <iostream>
using namespace std;
long long a,b,c;
long long qpow(long long a,long long b,long long c)
{
 long long ans=1;
 while(b>0)
 {
  if(b%2)ans=((ans%c)*(a%c))%c;//这里防爆long long
  a=a*a%c;
  b>>=1;
 }
 return ans%c;
}
int main()
{
 cin>>a>>b>>c;
 cout<<qpow(a,b,c);
 return 0;
}
