#include <cstdio>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
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
 freopen("game.in","r",stdin);
 freopen("game.out","w",stdout);
 int n,m;
 cin>>n>>m;
 if(n>m)swap(n,m);
 if(n==1)cout<<fpow(2,m)<<endl;
 else if(n==2)cout<<4*fpow(3,m-1)%MOD<<endl;
 else if(n==3)cout<<112*fpow(3,m-3)%MOD<<endl;
 else
 {
  if(n==m)
   cout<<(83*fpow(8,n)+5*fpow(2,n+7))%MOD*fpow(384,MOD-2)%MOD<<endl;
  else
   cout<<(83*fpow(8,n)+fpow(2,n+8))%MOD*fpow(128,MOD-2)%MOD*fpow(3,m-n-1)%MOD<<endl;
 }
 return 0;
}