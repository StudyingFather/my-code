#include <cstring>
#include <iostream>
#define MOD 1000000007
using namespace std;
long long n,k;
struct mat
{
 long long a[15][15];
 mat(int x=0)
 {
  memset(a,0,sizeof(a));
  for(int i=0;i<=k;i++)
   a[i][i]=x;
 }
 mat operator*(const mat&b)const
 {
  mat ans;
  for(int l=0;l<=k+1;l++)
   for(int i=0;i<=k+1;i++)
    for(int j=0;j<=k+1;j++)
     ans.a[i][j]=(ans.a[i][j]+a[i][l]*b.a[l][j])%MOD;
  return ans;
 }
}f,g;
void init()
{
 //[n^0,n^1,...,n^k,s_0]
 for(int i=0;i<=k;i++)
  f.a[0][i]=1;
 for(int i=0;i<=k;i++)
  g.a[0][i]=1;
 for(int i=1;i<=k;i++)
  for(int j=1;j<=k;j++)
   g.a[i][j]=g.a[i-1][j-1]+g.a[i][j-1];
 g.a[k][k+1]=1,g.a[k+1][k+1]=2;
}
mat fpow(mat x,long long y)
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
 cin>>n>>k;
 init();
 long long res1=(f*fpow(g,n)).a[0][k+1],res2=(f*fpow(g,n-1)).a[0][k+1];
 cout<<(res1-res2+MOD)%MOD<<endl;
 return 0;
}