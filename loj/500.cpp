// Problem: #500. 「LibreOJ β Round」ZQC 的拼图
// Contest: LibreOJ
// URL: https://loj.ac/problem/500
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
using namespace std;
int n,m;
int f[105][105],a[105],b[105];
bool check(int x)
{
 memset(f,207,sizeof(f));
 f[0][0]=0;
 for(int i=1;i<=n;i++)
  for(int j=0;j<=m;j++)
   for(int k=0;k<=min(j,x/a[i]);k++)
    f[i][j]=max(f[i][j],f[i-1][j-k]+(x-a[i]*k)/b[i]);
 return f[n][m]>=m;
}
int main()
{
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  cin>>a[i]>>b[i];
 int l=1,r=2e8,ans=0;
 while(l<=r)
 {
  int mid=(l+r)>>1;
  if(check(mid))ans=mid,r=mid-1;
  else l=mid+1;
 }
 cout<<ans<<endl;
 return 0;
}