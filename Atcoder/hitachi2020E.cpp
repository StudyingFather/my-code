#include <iostream>
using namespace std;
int a[2005][2005];
void solve(int x)
{
 if(x==1)
 {
  a[1][1]=1;
  return;
 }
 solve(x-1);
 int l=(1<<(x-1));
 for(int i=1;i<l;i++)
  for(int j=1;j<l;j++)
   a[i+l][j]=a[i][j+l]=a[i+l][j+l]=a[i][j];
 a[l][l]=1;
}
int main()
{
 int n,m;
 cin>>n>>m;
 solve(max(n,m));
 for(int i=1;i<(1<<n);i++)
 {
  for(int j=1;j<(1<<m);j++)
   cout<<a[i][j];
  cout<<endl;
 }
 return 0;
}