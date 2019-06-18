#include <iostream>
#define MOD 9999973
using namespace std;
long long f[105][105][105],ans;
long long C(long long a)
{
 return a*(a-1)/2;
}
int main()
{
 int n,m;
 cin>>n>>m;
 f[0][0][0]=1;
 for(int i=0;i<n;i++)
  for(int j=0;j<=m;j++)
   for(int k=0;j+k<=m;k++)
    if(f[i][j][k])
    {
     f[i+1][j][k]=(f[i+1][j][k]+f[i][j][k])%MOD;
     if(m-j-k>=1)f[i+1][j+1][k]=(f[i+1][j+1][k]+f[i][j][k]*(m-j-k))%MOD;
     if(j>=1)f[i+1][j-1][k+1]=(f[i+1][j-1][k+1]+f[i][j][k]*j)%MOD;
     if(m-j-k>=2)f[i+1][j+2][k]=(f[i+1][j+2][k]+f[i][j][k]*C(m-j-k))%MOD;
     if(m-j-k>=1&&j>=1)f[i+1][j][k+1]=(f[i+1][j][k+1]+f[i][j][k]*(m-j-k)*j)%MOD;
     if(j>=2)f[i+1][j-2][k+2]=(f[i+1][j-2][k+2]+f[i][j][k]*C(j))%MOD;
    }
 for(int i=0;i<=m;i++)
  for(int j=0;i+j<=m;j++)
   ans=(ans+f[n][i][j])%MOD;
 cout<<ans;
 return 0;
}