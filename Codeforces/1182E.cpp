#include <cstring>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
struct mat
{
 int x[15][15];
 mat()
 {
  memset(x,0,sizeof(x));
 }
}m1,m2,m3,base,ans;
mat operator*(mat x,mat y)
{
 mat ans;
 for(int k=1;k<=5;k++)
  for(int i=1;i<=5;i++)
   for(int j=1;j<=5;j++)
    ans.x[i][j]=(ans.x[i][j]+x.x[i][k]*y.x[k][j])%(MOD-1);
  return ans;
}
mat fpow(mat x,long long y)
{
 mat ans=x;
 y--;
 while(y)
 {
  if(y&1)ans=ans*x;
  x=x*x;
  y>>=1;
 }
 return ans;
}
long long fpow(long long x,long long y)
{
 int ans=1;
 x%=MOD;
 while(y)
 {
  if(y&1)ans=ans*x%MOD;
  x=x*x%MOD;
  y>>=1;
 }
 return ans;
}
int main()
{
 long long n,f1,f2,f3,c;
 cin>>n>>f1>>f2>>f3>>c;
 //f4=1 1 1
 //f5=2 2 1
 //f6=4 3 2
 base.x[1][3]=base.x[2][3]=base.x[3][3]=base.x[2][1]=base.x[3][2]=1;
 long long res=1;
 ans.x[1][1]=0,ans.x[1][2]=0,ans.x[1][3]=1;
 res*=fpow(f3,(ans*fpow(base,n-3)).x[1][3]);
 res%=MOD;
 ans.x[1][1]=0,ans.x[1][2]=1,ans.x[1][3]=0;
 res*=fpow(f2,(ans*fpow(base,n-3)).x[1][3]);
 res%=MOD;
 ans.x[1][1]=1,ans.x[1][2]=0,ans.x[1][3]=0;
 res*=fpow(f1,(ans*fpow(base,n-3)).x[1][3]);
 res%=MOD;
 memset(base.x,0,sizeof(base.x));
 base.x[1][3]=base.x[2][1]=base.x[2][3]=base.x[3][2]=base.x[3][3]=base.x[4][3]=base.x[4][4]=base.x[5][4]=base.x[5][5]=1;
 memset(ans.x,0,sizeof(ans.x));
 ans.x[1][4]=2,ans.x[1][5]=2;
 res*=fpow(c,(ans*fpow(base,n-3)).x[1][3]);
 res%=MOD;
 cout<<res<<endl;
 return 0;
}
