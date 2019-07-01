#include <iostream>
using namespace std;
long long a[15],b[15],m[15],c[15],lcm=1,ans;
void ex_gcd(long long a,long long b,long long&x,long long&y)
{
 if(b==0)
 {
  x=1,y=0;
  return;
 }
 ex_gcd(b,a%b,x,y);
 long long tmp=x;
 x=y;
 y=tmp-a/b*y;
 return;
}
long long smul(long long x,long long y)
{
 long long ans=0;
 while(y)
 {
  if(y&1)ans=(ans+x)%lcm;
  x=(x+x)%lcm;
  y>>=1;
 }
 return ans;
}
int main()
{
 int k;
 cin>>k;
 for(int i=1;i<=k;i++)
  cin>>a[i];
 for(int i=1;i<=k;i++)
 {
  cin>>b[i];
  a[i]=(a[i]%b[i]+b[i])%b[i];
  lcm*=b[i];
 }
 for(int i=1;i<=k;i++)
 {
  long long x,y;
  m[i]=lcm/b[i];
  ex_gcd(m[i],b[i],x,y);
  x=(x+lcm)%lcm;
  c[i]=smul(m[i],x);
 }
 for(int i=1;i<=k;i++)
  ans=(ans+smul(a[i],c[i]))%lcm;
 cout<<(ans+lcm)%lcm<<endl;
 return 0;
}