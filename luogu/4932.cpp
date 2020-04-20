#include <iostream>
#define N 65535
using namespace std;
long long x[10000005];
int f[70005];
void init()
{
 for(int i=1;i<=N;i++)
  f[i]=f[i>>1]+(i&1);
}
int popcount(int x)
{
 return f[x&N]+f[(x>>16)&N];
}
int main()
{
 long long n,a,b,c,d,cnt1=0,cnt2=0;
 cin>>n>>a>>b>>c>>d>>x[0];
 init();
 for(int i=1;i<=n;i++)
 {
  x[i]=(a*x[i-1]%d*x[i-1]%d+b*x[i-1]%d+c)%d;
  if(popcount(x[i])%2)cnt1++;
  else cnt2++;
 }
 cout<<cnt1*cnt2<<endl;
 return 0;
}