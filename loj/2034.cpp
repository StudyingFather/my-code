#include <iostream>
using namespace std;
#define MOD 1000000007
#define N 1000000
long long d[N+5],f[N+5],invf[N+5];
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
long long C(int x,int y)
{
 return f[x]*invf[y]%MOD*invf[x-y]%MOD;
}
int main()
{
 ios::sync_with_stdio(false);
 int t;
 cin>>t;
 d[0]=1,d[1]=0;
 for(int i=2;i<=N;i++)
  d[i]=(i-1)*(d[i-1]+d[i-2])%MOD;
 f[0]=invf[0]=1;
 for(int i=1;i<=N;i++)
  f[i]=f[i-1]*i%MOD;
 invf[N]=fpow(f[N],MOD-2);
 for(int i=N-1;i;i--)
  invf[i]=invf[i+1]*(i+1)%MOD;
 while(t--)
 {
  int n,m;
  cin>>n>>m;
  cout<<d[n-m]*C(n,m)%MOD<<endl;
 }
 return 0;
}