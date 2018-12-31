#include <iostream>
using namespace std;
int main()
{
 long long n,k,ans=0;
 cin>>n>>k;
 long long l=1,r;
 while(l<=n)
 {
  int t=k/l;
  if(t==0)r=n;
  else r=min(k/t,n);
  ans+=t*(r-l+1)*(l+r)/2;
  l=r+1;
 }
 cout<<n*k-ans<<endl;
 return 0;
}
