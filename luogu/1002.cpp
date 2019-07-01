#include <iostream>
using namespace std;
long long a[1005][1005];
int main()
{
 int x1,y1,x2,y2;
 cin>>x1>>y1>>x2>>y2;
 x1+=2;y1+=2;x2+=2;y2+=2;
 for(int i=2;i<=x1;i++)
  for(int j=2;j<=y1;j++)
   {
    a[2][2]=1;
    a[x2][y2]=0;
    a[x2+2][y2+1]=0;
    a[x2+1][y2+2]=0;
    a[x2-1][y2+2]=0;
    a[x2-2][y2+1]=0;
    a[x2-2][y2-1]=0;
    a[x2-1][y2-2]=0;
    a[x2+1][y2-2]=0;
    a[x2+2][y2-1]=0;
    a[i][j]=a[i-1][j]+a[i][j-1];
   }
 cout<<a[x1][y1]<<endl;
 return 0;
}
