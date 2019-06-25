#include <iostream>
using namespace std;
int t,k,n,m;
long long f[2005][2005],s[2005][2005];
int main()
{
 cin>>t>>k;
 for(int i=0;i<=2000;i++)
 {
  f[i][i]=1;
  f[i][0]=1;
 }
 for(int i=1;i<=2000;i++)
  for(int j=1;j<i;j++)
   f[i][j]=(f[i-1][j-1]+f[i-1][j])%k;
 for(int i=1;i<=2000;i++)
  for(int j=1;j<=2000;j++)
  {
   s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1];
    if(f[i][j]==0&&j<=i)s[i][j]++;
  }
 while(t--)
 {
  cin>>n>>m;
  cout<<s[n][m]<<endl;
 }
 return 0;
}
