#include <iostream>
#define MOD 1000000007
using namespace std;
long long a[105][105],f[105][105];
int main()
{
 int r,c,k;
 cin>>r>>c>>k;
 for(int i=1;i<=r;i++)
  for(int j=1;j<=c;j++)
   cin>>a[i][j];
 f[1][1]=1;
 for(int i=1;i<=r;i++)
  for(int j=1;j<=c;j++)
   for(int k=1;k<i;k++)
    for(int l=1;l<j;l++)
     if(a[i][j]!=a[k][l])f[i][j]=(f[i][j]+f[k][l])%MOD;
 cout<<f[r][c]<<endl;
 return 0;
}
