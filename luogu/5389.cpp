/*
 Name: luogu P5389
 Author: StudyingFather
 Date: 2019/10/30 12:22
 Website: https://studyingfather.com
*/
#include <iostream>
#define MOD 998244353
#define INV2 499122177
using namespace std;
long long fpow(long long x,long long y)
{
 long long ans=1;
 while(y)
 {
  if(y&1)ans=ans*x%MOD;
  x=x*x%MOD;
  y>>=1;
 }
 return ans;
}
int main()
{
 long long n;
 cin>>n;
 n%=MOD;
 if(n==0)cout<<INV2<<endl;
 else cout<<(1-(3*fpow(n,MOD-2)*fpow(n+2,MOD-2)%MOD)+MOD)*INV2%MOD<<endl;
 return 0;
}