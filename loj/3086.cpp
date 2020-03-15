#include <cstring>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
struct mat
{
 long long a[15][15];
 mat(int x=0)
 {
  memset(a,0,sizeof(a));
  for(int i=1;i<=6;i++)
   a[i][i]=x;
 }
 mat operator*(const mat&A)const
 {
  mat ans;
  for(int k=1;k<=6;k++)
   for(int i=1;i<=6;i++)
    for(int j=1;j<=6;j++)
     ans.a[i][j]=(ans.a[i][j]+a[i][k]*A.a[k][j])%MOD;
  return ans;
 }
}f,g;
void init()
{
 //[f_3,f_2,f_1,g_3,g_2,g_1]
 f.a[1][1]=3,f.a[1][2]=2,f.a[1][3]=1,f.a[1][4]=10,f.a[1][5]=5,f.a[1][6]=2;
 /*
 1 1 0 1 0 0
 1 0 1 1 0 0
 0 0 0 0 0 0
 0 0 0 1 1 0
 0 0 0 1 0 1
 0 0 0 0 0 0
 */
 g.a[1][1]=1,g.a[1][2]=1,g.a[1][3]=0,g.a[1][4]=1,g.a[1][5]=0,g.a[1][6]=0;
 g.a[2][1]=1,g.a[2][2]=0,g.a[2][3]=1,g.a[2][4]=1,g.a[2][5]=0,g.a[2][6]=0;
 g.a[3][1]=0,g.a[3][2]=0,g.a[3][3]=0,g.a[3][4]=0,g.a[3][5]=0,g.a[3][6]=0;
 g.a[4][1]=0,g.a[4][2]=0,g.a[4][3]=0,g.a[4][4]=1,g.a[4][5]=1,g.a[4][6]=0;
 g.a[5][1]=0,g.a[5][2]=0,g.a[5][3]=0,g.a[5][4]=1,g.a[5][5]=0,g.a[5][6]=1;
 g.a[6][1]=0,g.a[6][2]=0,g.a[6][3]=0,g.a[6][4]=0,g.a[6][5]=0,g.a[6][6]=0;
}
mat fpow(mat x,int y)
{
 mat ans(1);
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
 int t;
 cin>>t;
 init();
 while(t--)
 {
  int n;
  cin>>n;
  if(n<=2)cout<<0<<endl;
  else
  {
   mat res=f*fpow(g,n-3);
   cout<<(2*(-2*res.a[1][2]-res.a[1][3]+res.a[1][5]+1)%MOD+MOD)%MOD<<endl;
  }
 }
 return 0;
}