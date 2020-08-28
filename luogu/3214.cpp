// Problem: P3214 [HNOI2011]卡农
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3214
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#define MOD 100000007
using namespace std;
long long a[1000005],f[1000005];
int n,m;
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
long long frac(int x)
{
 long long ans=1;
 while(x)
  ans=ans*x%MOD,x--;
 return ans;
}
int main()
{
 cin>>n>>m;
 int tot=fpow(2,n)-1;
 a[0]=1;
 for(int i=1;i<=m;i++)
  a[i]=a[i-1]*(tot-i+1+MOD)%MOD;
 f[0]=1;
 for(int i=2;i<=m;i++)
 {
  f[i]=a[i-1];
  f[i]=(f[i]-f[i-1]+MOD)%MOD;
  f[i]=(f[i]-f[i-2]*(i-1)%MOD*(tot-(i-2))%MOD+MOD)%MOD;
 }
 cout<<f[m]*fpow(frac(m),MOD-2)%MOD<<endl;
 return 0;
}