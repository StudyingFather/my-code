#include <iostream>
#define MOD 100003
using namespace std;
long long fpow(long long a,long long b)
{
 long long ans=1;
 while(b)
 {
  if(b&1)ans=ans*a%MOD;
  a=a*a%MOD;
  b>>=1;
 }
 return ans;
}
int main()
{
 long long m,n;
 cin>>m>>n;
 cout<<(fpow(m,n)-(m%MOD)*fpow(m-1,n-1)%MOD+MOD)%MOD<<endl;
 return 0;
}