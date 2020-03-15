#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
struct mat
{
 char a[15][15];
 mat()
 {
  memset(a,0,sizeof(a));
 }
 void input()
 {
  for(int i=0;i<n;i++)
   scanf("%s",a[i]);
 }
 mat rotate()
 {
  mat res;
  for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
    res.a[i][j]=a[n-j-1][i];
  return res;
 }
 mat mirror()
 {
  mat res;
  for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
    res.a[i][j]=a[i][n-j-1];
  return res;
 }
 bool operator==(const mat&x)const
 {
  for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
    if(a[i][j]!=x.a[i][j])return false;
  return true;
 }
}a,b,c;
int main()
{
 scanf("%d",&n);
 a.input(),c.input();
 b=a;
 int ans=7;
 for(int i=1;i<=n;i++)
 {
  b=b.rotate();
  if(b==c)ans=min(ans,i);
 }
 b=a.mirror();
 if(b==c)ans=min(ans,4);
 for(int i=1;i<=3;i++)
 {
  b=b.rotate();
  if(b==c)ans=min(ans,5);
 }
 if(a==c)ans=min(ans,6);
 printf("%d\n",ans);
 return 0;
}