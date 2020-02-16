#include <iostream>
#include <cstdio>
#include <algorithm>
#define MOD 10007
using namespace std;
int a,b,k,n,m;
inline int inv(int x)
{
 for(int i=1;;i++)
  if(i*x%MOD==1)return i;
}
inline long long c(int x,int y)
{
 long long ans=1;
 for(int i=1;i<=y;i++)
 {
  ans=ans*(x-i+1);
  ans*=inv(i);
  ans%=MOD;
 }
 return ans;
}
inline long long pow(int x,int y)
{
 long long ans=1;
 for(int i=1;i<=y;i++)
  ans*=x,ans%=MOD;
 return ans;
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>a>>b>>k>>n>>m;
 if(a==1&&b==1)cout<<c(k,min(n,m))<<endl;
 else cout<<c(k,n)*pow(a,n)*pow(b,m)%MOD<<endl;
 return 0;
}