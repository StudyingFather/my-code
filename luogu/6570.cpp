// Problem : P6570 [NOI Online #3 提高组]优秀子序列（民间数据）
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P6570
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
int phi[400005],pri[400005],a[400005],cnt;
long long f[400005];
int fpow(int x,int y)
{
 int ans=1;
 for(int i=1;i<=y;i++)
  ans=ans*x%MOD;
 return ans;
}
int main()
{
 int n,mx=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  a[x]++;
  mx=max(mx,x);
 }
 phi[1]=1;
 int w=0;
 while(mx>=(1<<w))
  w++;
 for(int i=2;i<=(1<<w);i++)
 {
  if(!phi[i])
   pri[++cnt]=i,phi[i]=i-1;
  for(int j=1;j<=cnt&&i*pri[j]<=(1<<w);j++)
  {
   if(i%pri[j]!=0)
    phi[i*pri[j]]=phi[i]*phi[pri[j]];
   else
   {
    phi[i*pri[j]]=phi[i]*pri[j];
    break;
   }
  }
 }
 f[0]=fpow(2,a[0]);
 int p=0;
 for(int i=1;i<=mx;i++)
  if(a[i])
  {
   p|=i;
   int s=p^i;
   for(int t=s;;t=(t-1)&s)
   {
    f[i|t]=(f[i|t]+f[t]*a[i])%MOD;
    if(!t)break;
   }
  }
 long long ans=0;
 for(int i=0;i<(1<<w);i++)
  ans=(ans+f[i]*phi[i+1])%MOD;
 cout<<ans<<endl;
 return 0;
}