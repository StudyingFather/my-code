#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int dp[105][105];
int main()
{
 int t,n,m;
 cin>>t;
 for(int i=1;i<=t;i++)
 {
  cin>>n>>m;
  memset(dp,0,sizeof(dp));
  for(int j=1;j<=n;j++)
   dp[1][j]=1;
  for(int j=1;j<=m;j++)
   dp[j][0]=1;
  for(int j=2;j<=m;j++)
   for(int k=1;k<=n;k++)
   {
    dp[j][k]=dp[j-1][k];
    if(k>=j)dp[j][k]+=dp[j][k-j];
   }
  cout<<dp[m][n]<<endl;
 }
 return 0;
}
