#include <iostream>
#define MOD 1000000007
using namespace std;
struct mat
{
 long long a[2][2];
}a,ans,tmp;
inline mat mat_c(mat x,mat y)
{
 for(int i=0;i<2;i++)
  for(int j=0;j<2;j++)
  {
   tmp.a[i][j]=0;
   for(int k=0;k<2;k++)
   {
    tmp.a[i][j]+=(x.a[i][k]*y.a[k][j])%MOD;
    tmp.a[i][j]%=MOD;
   }
  }
 return tmp;
}
int main()
{
 long long n;
 cin>>n;
 a.a[0][0]=1,a.a[0][1]=1,a.a[1][0]=1,a.a[1][1]=0;
 ans.a[0][0]=1,ans.a[0][1]=0,ans.a[1][0]=0,ans.a[1][1]=1;
 n--;
 while(n)
 {
  if(n%2)ans=mat_c(ans,a);
  a=mat_c(a,a);
  n>>=1;
 }
 cout<<ans.a[0][0]<<endl;
 return 0;
}