#include <iostream>
#include <algorithm>
using namespace std;
int t[1000005],f[1000005][5][5];
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  t[x]++;
 }
 for(int p=1;p<=m;p++)
  for(int i=0;i<3;i++)
   for(int j=0;j<3;j++)
    for(int k=0;k<3;k++)
      if(i+j+k<=t[p])
       f[p][j][k]=max(f[p][j][k],f[p-1][i][j]+(t[p]-i-j-k)/3+k);
 cout<<f[m][0][0]<<endl;
 return 0;
}