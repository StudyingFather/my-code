#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,ma[205][205];
int main()
{
 memset(ma,0x3f,sizeof(ma));
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  ma[i][i]=0;
 for(int i=1;i<=n;i++)
  for(int j=i+1;j<=n;j++)
   scanf("%d",&ma[i][j]);
 for(int k=1;k<=n;k++)
  for(int i=1;i<=n;i++)
   for(int j=i+1;j<=n;j++)
    if(i<k)ma[i][j]=min(ma[i][j],ma[i][k]+ma[k][j]);
 printf("%d",ma[1][n]);
 return 0;
}
