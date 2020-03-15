#include <iostream>
#include <algorithm>
#define MOD 1024523
using namespace std;
int f[2][505][505];
char s[505],t[505];
int a[505],b[505];
int main()
{
 int n,m;
 cin>>n>>m;
 cin>>(s+1);
 cin>>(t+1);
 for(int i=1;i<=n;i++)
  a[i]=(s[n-i+1]=='A');
 for(int i=1;i<=m;i++)
  b[i]=(t[m-i+1]=='A');
 f[0][0][0]=1;
 for(int k=1;k<=n+m;k++)
 {
  int p=k&1,q=p^1;
  for(int i=0;i<=n;i++)
   for(int j=0;j<=n;j++)
    f[p][i][j]=0;
  for(int i=max(k-m,0);i<=min(n,k);i++)
   for(int j=max(k-m,0);j<=min(n,k);j++)
   {
    if(i&&j&&a[i]==a[j])
     f[p][i][j]=(f[p][i][j]+f[q][i-1][j-1])%MOD;
    if(i&&k-j&&a[i]==b[k-j])
     f[p][i][j]=(f[p][i][j]+f[q][i-1][j])%MOD;
    if(j&&k-i&&a[j]==b[k-i])
     f[p][i][j]=(f[p][i][j]+f[q][i][j-1])%MOD;
    if(k-j&&k-i&&b[k-j]==b[k-i])
     f[p][i][j]=(f[p][i][j]+f[q][i][j])%MOD;
   }
 }
 cout<<f[(n+m)&1][n][n]<<endl;
 return 0;
}