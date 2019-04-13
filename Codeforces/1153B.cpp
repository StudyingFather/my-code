#include <cstdio>
#include <algorithm>
using namespace std;
int a[105],b[105],h[105][105],res[105][105];
int main()
{
 int n,m,w;
 scanf("%d%d%d",&n,&m,&w);
 for(int i=1;i<=m;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  scanf("%d",&b[i]);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   scanf("%d",&h[i][j]);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   if(h[i][j]==0)res[i][j]=0;
   else res[i][j]=min(a[j],b[i]);
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=m;j++)
   printf("%d ",res[i][j]);
  puts("");
 }
 return 0;
}