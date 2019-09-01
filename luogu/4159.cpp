/*
 Name: luogu P4159
 Author: StudyingFather
 Date: 2019/08/10 15:44
 Website: https://studyingfather.com
*/
#include <iostream>
#include <cstring>
#define MOD 2009
using namespace std;
struct mat
{
 int a[105][105];
 mat()
 {
  memset(a,0,sizeof(a));
 }
}f;
long long n,t;
char s[15];
mat operator*(mat a,mat b)
{
 mat ans;
 for(int k=1;k<=n*9+1;k++)
  for(int i=1;i<=n*9+1;i++)
   for(int j=1;j<=n*9+1;j++)
    ans.a[i][j]=(ans.a[i][j]+a.a[i][k]*b.a[k][j])%MOD;
 return ans;
}
mat fpow(mat x,long long y)
{
 mat ans;
 for(int i=1;i<=n*9+1;i++)
  ans.a[i][i]=1;
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
 cin>>n>>t;
 for(int i=0;i<n;i++)
 {
  cin>>s;
  for(int j=i*9+1;j<=i*9+8;j++)
   f.a[j][j+1]=1;
  for(int j=0;j<n;j++)
   if(s[j]-='0')
    f.a[i*9+s[j]][j*9+1]=1;
 }
 cout<<fpow(f,t).a[1][(n-1)*9+1]<<endl;
 return 0;
}