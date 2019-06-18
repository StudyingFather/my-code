#include <iostream>
#define MOD 1000000007
using namespace std;
long long w,n,k,x,y;
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
void ex_gcd(long long a,long long b,long long&x,long long&y)
{
 if(b==0)
 {
  x=1,y=0;
  return;
 }
 ex_gcd(b,a%b,x,y);
 int t=x;
 x=y;
 y=t-a/b*y;
 return;
}
int main()
{
 cin>>w>>n>>k;
 ex_gcd(fpow(2,k),MOD,x,y);
 cout<<w*(x+MOD)%MOD<<endl;
 return 0;
}