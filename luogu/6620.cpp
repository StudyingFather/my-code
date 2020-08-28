// Problem : P6620 [省选联考 2020 A 卷] 组合数问题
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P6620
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int n,x,p,m;
long long a[1005],b[1005];
long long s[1005][1005];
long long f[1005],g[1005],h[1005];
long long fpow(long long x,long long y)
{
 long long ans=1;
 while(y)
 {
  if(y&1)ans=ans*x%p;
  x=x*x%p;
  y>>=1;
 }
 return ans;
}
int main()
{
 cin>>n>>x>>p>>m;
 for(int i=0;i<=m;i++)
  cin>>a[i];
 s[0][0]=1;
 for(int i=1;i<=m;i++)
  for(int j=1;j<=i;j++)
   s[i][j]=(j*s[i-1][j]+s[i-1][j-1])%p;
 for(int i=0;i<=m;i++)
  for(int j=i;j<=m;j++)
   b[i]=(b[i]+s[j][i]*a[j])%p;
 f[0]=1,g[0]=1,h[m]=fpow(x+1,n-m);
 for(int i=1;i<=m;i++)
 {
  f[i]=f[i-1]*(n-i+1)%p;
  g[i]=g[i-1]*x%p;
 }
 for(int i=m-1;i>=0;i--)
  h[i]=h[i+1]*(x+1)%p;
 long long ans=0;
 for(int i=0;i<=m;i++)
  ans=(ans+b[i]*f[i]%p*g[i]%p*h[i])%p;
 cout<<ans<<endl;
 return 0;
}