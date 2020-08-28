// Problem: P6086 【模板】Prufer 序列
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P6086
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
int f[5000005],p[5000005],d[5000005],n,m;
void treeToPrufer()
{
 for(int i=1;i<=n-1;i++)
  cin>>f[i],d[f[i]]++;
 for(int i=1,j=1;i<=n-2;i++,j++)
 {
  while(d[j])
   j++;
  p[i]=f[j];
  for(;i<=n-2;i++)
  {
   d[p[i]]--;
   if(d[p[i]]||p[i]>=j)break;
   p[i+1]=f[p[i]];
  }
 }
 long long ans=0;
 for(int i=1;i<=n-2;i++)
  ans^=1ll*i*p[i];
 cout<<ans<<endl;
}
void pruferToTree()
{
 for(int i=1;i<=n-2;i++)
  cin>>p[i],d[p[i]]++;
 p[n-1]=n;
 for(int i=1,j=1;i<=n-1;i++,j++)
 {
  while(d[j])
   j++;
  f[j]=p[i];
  for(;i<=n-1;i++)
  {
   d[p[i]]--;
   if(d[p[i]]||p[i]>=j)break;
   f[p[i]]=p[i+1];
  }
 }
 long long ans=0;
 for(int i=1;i<=n-1;i++)
  ans^=1ll*i*f[i];
 cout<<ans<<endl;
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>m;
 if(m==1)treeToPrufer();
 else pruferToTree();
 return 0;
}