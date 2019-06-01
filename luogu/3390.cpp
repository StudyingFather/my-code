#include <cstring>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
long long n,k;
struct mat
{
 long long x[105][105];
 mat()
 {
  memset(x,0,sizeof(x));
 }
}a;
mat operator*(mat x,mat y)
{
 mat ans;
 for(int k=1;k<=n;k++)
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    ans.x[i][j]=(ans.x[i][j]+x.x[i][k]*y.x[k][j])%MOD;
  return ans;
}
mat fpow(mat x,long long y)
{
 mat ans;
 for(int i=1;i<=n;i++)
  ans.x[i][i]=1;
 while(y)
 {
  if(y&1)ans=ans*x;
  x=x*x;
  y>>=1;
 }
 return ans;
}
int main()
{
 cin>>n>>k;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   cin>>a.x[i][j];
 mat ans=fpow(a,k);
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
   cout<<ans.x[i][j]<<' ';
  cout<<endl;
 }
 return 0;
}