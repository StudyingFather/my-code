// Problem: P5228 [AHOI2013]找硬币
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5228
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[55],f[5000005];
int main()
{
 int n;
 cin>>n;
 memset(f,63,sizeof(f));
 f[1]=0;
 int maxa=0;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  f[1]+=a[i];
  maxa=max(maxa,a[i]);
 }
 int ans=f[1];
 for(int i=1;i<=maxa;i++)
  for(int j=2;i*j<=maxa;j++)
  {
   int sum=0;
   for(int k=1;k<=n;k++)
    sum+=a[k]/(i*j);
   f[i*j]=min(f[i*j],f[i]-(j-1)*sum);
   ans=min(ans,f[i*j]);
  }
 cout<<ans<<endl;
 return 0;
}