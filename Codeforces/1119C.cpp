#include <iostream>
using namespace std;
int a[505][505],b[505][505];
int px[505],py[505],qx[505],qy[505];
int main()
{
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   cin>>a[i][j];
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   cin>>b[i][j];
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
   px[i]^=a[i][j];
   qx[i]^=b[i][j];
  }
 for(int j=1;j<=m;j++)
  for(int i=1;i<=n;i++)
  {
   py[j]^=a[i][j];
   qy[j]^=b[i][j];
  }
 for(int i=1;i<=n;i++)
  if(px[i]!=qx[i])
  {
   cout<<"No"<<endl;
   return 0;
  }
 for(int i=1;i<=m;i++)
  if(py[i]!=qy[i])
  {
   cout<<"No"<<endl;
   return 0;
  }
 cout<<"Yes"<<endl;
 return 0;
}