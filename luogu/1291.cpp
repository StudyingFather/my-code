#include <iostream>
using namespace std;
long long p,q=1;
long long gcd(long long a,long long b)
{
 return b==0?a:gcd(b,a%b);
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  p=p*i+q;
  q*=i;
  int tmp=gcd(p,q);
  p/=tmp;
  q/=tmp;
 }
 p*=n;
 int tmp=gcd(p,q);
 p/=tmp;
 q/=tmp;
 if(q==1)cout<<p<<endl;
 else if(p<q)cout<<p<<'/'<<q<<endl;
 else
 {
  long long x=p/q,ws1=0,ws2=0,x1=x;
  p%=q;
  while(x1)
  {
   ws1++;
   x1/=10;
  }
  for(int i=1;i<=ws1;i++)
   cout<<' ';
  cout<<p<<endl;
  cout<<x;
  x1=q;
  while(x1)
  {
   ws2++;
   x1/=10;
  }
  for(int i=1;i<=ws2;i++)
   cout<<'-';
  cout<<endl;
  for(int i=1;i<=ws1;i++)
   cout<<' ';
  cout<<q<<endl;
 }
 return 0;
}