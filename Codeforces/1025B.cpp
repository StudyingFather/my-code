#include <iostream>
using namespace std;
long long lcmnum[150005];
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
  long long x,y;
  cin>>x>>y;
  if(n==1)
  {
   cout<<x;
   return 0;
  }
  lcmnum[i]=x*y/gcd(x,y);
 }
 long long ans=lcmnum[1];
 for(int i=1;i<n;i++)
  ans=gcd(ans,lcmnum[i+1]);
 for(int i=2;i*i<=ans;i++)
  if(ans%i==0)
  {
   cout<<i;
   return 0;
  }
 if(ans==1)cout<<-1;
 else cout<<ans;
 return 0;
}
