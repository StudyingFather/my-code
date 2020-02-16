#include <iostream>
using namespace std;
long long n,m,k,x;
long long fpow(long long a,long long b)
{
 long long ans=1;
 while(b)
 {
  if(b&1)ans=ans*a%n;
  a=a*a%n;
  b>>=1;
 }
 return ans;
}
int main()
{
 cin>>n>>m>>k>>x;
 cout<<(x+fpow(10,k)*m)%n<<endl;
 return 0;
}