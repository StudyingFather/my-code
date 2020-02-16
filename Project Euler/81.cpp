#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int a[105][105],f[105][105];
int main()
{
 for(int i=1;i<=80;i++)
  for(int j=1;j<=80;j++)
   scanf("%d",&a[i][j]);
 memset(f,INF,sizeof(f));
 f[1][1]=a[1][1];
 for(int i=1;i<=80;i++)
  for(int j=1;j<=80;j++)
  {
   if(i!=1)f[i][j]=min(f[i][j],f[i-1][j]+a[i][j]);
   if(j!=1)f[i][j]=min(f[i][j],f[i][j-1]+a[i][j]);
  }
 printf("%d\n",f[80][80]);
 return 0;
}