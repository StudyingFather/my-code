/*
 Name: luogu P1349
 Author: StudyingFather
 Date: 2019/09/01 22:04
 Website: https://studyingfather.com
*/
#include <cstring>
#include <iostream>
using namespace std;
struct mat
{
 long long a[5][5];
 mat()
 {
  memset(a,0,sizeof(a));
 }
};
long long p,q,a1,a2,n,m;
mat operator*(mat a,mat b)
{
 mat ans;
 for(int k=1;k<=2;k++)
  for(int i=1;i<=2;i++)
   for(int j=1;j<=2;j++)
    ans.a[i][j]=(ans.a[i][j]+a.a[i][k]*b.a[k][j])%m;
 return ans;
}
mat fpow(int x)
{
 mat ans,base;
 base.a[1][1]=p,base.a[1][2]=1,base.a[2][1]=q;
 ans.a[1][1]=a2,ans.a[1][2]=a1;
 while(x)
 {
  if(x&1)ans=ans*base;
  base=base*base;
  x>>=1;
 }
 return ans;
}
int main()
{
 cin>>p>>q>>a1>>a2>>n>>m;
 if(n==1)cout<<a1<<endl;
 else if(n==2)cout<<a2<<endl;
 else cout<<fpow(n-2).a[1][1]<<endl;
 return 0;
}