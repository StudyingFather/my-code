#include <iostream>
#define N 5000000
#define MOD 998244353
using namespace std;
long long f[N+5],invf[N+5],s[N+5],ms[N+5],invms[N+5],g[N+5];
long long mul;
long long n,m,l,k;
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
void init()
{
 f[0]=invf[0]=1;
 for(int i=1;i<=N;i++)
  f[i]=f[i-1]*i%MOD;
 invf[N]=fpow(f[N],MOD-2);
 for(int i=N-1;i;i--)
  invf[i]=invf[i+1]*(i+1)%MOD;
}
long long C(int x,int y)
{
 return f[x]*invf[y]%MOD*invf[x-y]%MOD;
}
long long A(int x,int y)
{
 return f[x]*invf[x-y]%MOD;
}
int main()
{
 int t;
 cin>>t;
 init();
 while(t--)
 {
  cin>>n>>m>>l>>k;
  int p=min(n,min(m,l));
  mul=n*m%MOD*l%MOD;
  ms[0]=invms[0]=1;
  for(int i=1;i<=p;i++)
  {
   s[i]=((mul-(n-i)*(m-i)%MOD*(l-i))%MOD+MOD)%MOD;
   ms[i]=ms[i-1]*s[i]%MOD;
  }
  invms[p]=fpow(ms[p],MOD-2);
  for(int i=p-1;i;i--)
   invms[i]=invms[i+1]*s[i+1]%MOD;
  for(int i=1;i<=p;i++)
   g[i]=A(n,i)*A(m,i)%MOD*A(l,i)%MOD*invms[i]%MOD;
  long long ans=0;
  for(int i=k;i<=p;i++)
  {
   long long tmp=C(i,k)*g[i]%MOD;
   if((i-k)&1)ans=(ans-tmp+MOD)%MOD;
   else ans=(ans+tmp)%MOD;
  }
  cout<<ans<<endl;
 }
 return 0;
}