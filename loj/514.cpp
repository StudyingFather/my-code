// Problem: #514. 「LibreOJ β Round #2」模拟只会猜题意
// Contest: LibreOJ
// URL: https://loj.ac/problem/514
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
using namespace std;
int a[10005],s[10005],f[10005];
int main()
{
 ios::sync_with_stdio(false);
 memset(f,191,sizeof(f));
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  cin>>a[i],s[i]=s[i-1]+a[i];
 for(int i=1;i<=n;i++)
  for(int j=i;j<=n;j++)
   f[j-i+1]=max(f[j-i+1],s[j]-s[i-1]);
 for(int i=n-1;i;i--)
  f[i]=max(f[i],f[i+1]);
 while(m--)
 {
  int x;
  cin>>x;
  cout<<f[x]<<endl;
 }
 return 0;
}