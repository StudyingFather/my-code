#include <iostream>
#include <cstdio>
using namespace std;
long long ans,n,k;
int main()
{
 cin>>n>>k;
 long long gai=n/k;
 ans+=gai+n;
 while(gai>=k)
 {
  ans+=gai/k;
  gai=gai%k+gai/k;
 }
 cout<<ans;
 return 0;
}
