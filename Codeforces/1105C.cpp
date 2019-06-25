#include <iostream>
#include <algorithm>
#define MOD 1000000007 
using namespace std;
long long t[3],f[200005][3];
int main()
{
 int n,l,r;
 scanf("%d%d%d",&n,&l,&r);
 t[0]=r/3-(l-1)/3;
 t[1]=(r+1)/3-l/3;
 t[2]=(r+2)/3-(l+1)/3;
 f[0][0]=1;
 for(int i=1;i<=n;i++)
  for(int j=0;j<=2;j++)
   for(int k=0;k<=2;k++)
    f[i][(k+j)%3]=(f[i][(k+j)%3]+f[i-1][j]*t[k]%MOD)%MOD;
 cout<<f[n][0]<<endl;
 return 0;
}