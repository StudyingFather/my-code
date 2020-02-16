#include <cmath>
#include <iostream>
using namespace std;
long long gcd(long long x,long long y)
{
 return y==0?x:gcd(y,x%y);
}
long long calc(long long x,long long y)
{
 long long p=gcd(x,y);
 x/=p,y/=p;
 return p*(long long)sqrt(x)*(long long)sqrt(y);
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  long long g,l;
  cin>>g>>l;
  cout<<2*calc(g,l)<<' '<<g+l<<endl;
 }
 return 0;
}