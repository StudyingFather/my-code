/*
 Name: luogu P1373
 Author: StudyingFather
 Date: 2019/08/03 20:19
 Website: https://studyingfather.com
*/
#include <iostream>
#define MOD 1000000007
using namespace std;
int f[805][805][20][2],a[805][805],ans;
int main()
{
 int n,m,k;
 cin>>n>>m>>k;
 k++;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
   cin>>a[i][j];
   f[i][j][a[i][j]%k][0]=1;
  }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   for(int l=0;l<=k;l++)
   {
    f[i][j][l][0]=(f[i][j][l][0]+f[i][j-1][(l-a[i][j]+k)%k][1])%MOD;
    f[i][j][l][0]=(f[i][j][l][0]+f[i-1][j][(l-a[i][j]+k)%k][1])%MOD;
    f[i][j][l][1]=(f[i][j][l][1]+f[i][j-1][(l+a[i][j])%k][0])%MOD;
    f[i][j][l][1]=(f[i][j][l][1]+f[i-1][j][(l+a[i][j])%k][0])%MOD;
   }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   ans=(ans+f[i][j][0][1])%MOD;
 cout<<ans<<endl;
 return 0;
}