#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,ma[1005][1005],a[1005][1005],b[1005][1005],f[1005],x[1005],y[1005];
int calc(int i,int j)
{
 if(a[i][j]>b[i][j])return max(y[j]+a[i][j]-b[i][j],x[i]);
 return max(y[j],x[i]+b[i][j]-a[i][j]);
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   scanf("%d",&ma[i][j]);
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=m;j++)
   f[j]=ma[i][j];
  sort(f+1,f+m+1);
  int k=unique(f+1,f+m+1)-(f+1);
  for(int j=1;j<=m;j++)
   x[i]=max(x[i],a[i][j]=lower_bound(f+1,f+k+1,ma[i][j])-f);
 }
 for(int j=1;j<=m;j++)
 {
  for(int i=1;i<=n;i++)
   f[i]=ma[i][j];
  sort(f+1,f+n+1);
  int k=unique(f+1,f+n+1)-(f+1);
  for(int i=1;i<=n;i++)
   y[j]=max(y[j],b[i][j]=lower_bound(f+1,f+k+1,ma[i][j])-f);
 }
 for(int i=1;i<=n;i++)
 {
  for(int j=1; j<=m; j++)
   printf("%d ",calc(i,j));
  puts("");
 }
 return 0;
}