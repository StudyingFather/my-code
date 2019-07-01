#include <iostream>
#include <algorithm>
#define G 3
#define MOD 998244353
using namespace std;
long long f[4000005],g[4000005],r[4000005],n,m,invn,invG;
int fpow(long long x,int y=MOD-2)
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
void ntt(long long *f,int op)
{
 for(int i=0;i<n;i++)
  if(i<r[i])swap(f[i],f[r[i]]);
 for(int p=2;p<=n;p<<=1)
 {
  int len=p>>1,w1=fpow(op==1?G:invG,(MOD-1)/p);
  for(int i=0;i<n;i+=p)
  {
   long long w=1;
   for(int j=i;j<i+len;j++)
   {
    int tmp=f[len+j]*w%MOD;
    f[len+j]=(f[j]-tmp+MOD)%MOD;
    f[j]=(f[j]+tmp)%MOD;
    w=w*w1%MOD;
   }
  }
 }
}
int main()
{
 cin>>n>>m;
 for(int i=0;i<=n;i++)
  cin>>f[i];
 for(int i=0;i<=m;i++)
  cin>>g[i];
 m+=n,n=1;
 while(n<=m)n<<=1;
 for(int i=0;i<n;i++)
  r[i]=(r[i>>1]>>1)|((i&1)?n>>1:0);
 invn=fpow(n),invG=fpow(G);
 ntt(f,1);
 ntt(g,1);
 for(int i=0;i<n;i++)
  f[i]=(f[i]*g[i])%MOD;
 ntt(f,-1);
 for(int i=0;i<=m;i++)
  cout<<(f[i]*invn)%MOD<<' ';
 return 0;
}