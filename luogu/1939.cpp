#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;
struct mat
{
 long long x[5][5];
 mat(int num=0)
 {
  memset(x,0,sizeof(x));
  for(int i=1;i<=3;i++)
   x[i][i]=num;
 }
}base;
mat operator*(mat a,mat b)
{
 mat ans;
 for(int k=1;k<=3;k++)
  for(int i=1;i<=3;i++)
   for(int j=1;j<=3;j++)
    ans.x[i][j]=(ans.x[i][j]+a.x[i][k]*b.x[k][j])%MOD;
 return ans;
}
mat fpow(mat a,long long b)
{
 mat ans(1);
 while(b)
 {
  if(b&1)ans=ans*a;
  a=a*a;
  b>>=1;
 }
 return ans;
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n;
  cin>>n;
  if(n<=3)cout<<1<<endl;
  else
  {
   base.x[1][1]=base.x[1][3]=base.x[2][1]=base.x[3][2]=1;
   cout<<fpow(base,n-1).x[1][1]<<endl;
  }
 }
 return 0;
}