// Problem: #515. 「LibreOJ β Round #2」贪心只能过样例
// Contest: LibreOJ
// URL: https://loj.ac/problem/515
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <bitset>
using namespace std;
bitset<1000005> f[105];
int main()
{
 int n;
 cin>>n;
 f[0][0]=1;
 for(int i=1;i<=n;i++)
 {
  int a,b;
  cin>>a>>b;
  for(int j=a;j<=b;j++)
   f[i]|=f[i-1]<<(j*j);
 }
 int ans=0;
 for(int i=1;i<=1000000;i++)
  ans+=f[n][i];
 cout<<ans<<endl;
 return 0;
}