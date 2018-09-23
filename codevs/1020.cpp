#include <cstdio>
#include <algorithm>
using namespace std;
int d[1001][1001];
int n,m,a,b,c=21474834,ans=-1;
int main()
{
 int x,y,z;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   d[i][j]=21474836;
 for(int i=1;i<=n;i++)
  d[i][i]=0;
 while(scanf("%d %d %d",&x,&y,&z)!=EOF)
 {
  d[x][y]=d[y][x]=z;
  m++;
 }
 for(int k=1;k<=n;k++)
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    if(d[i][k]+d[k][j]<d[i][j])d[i][j]=d[i][k]+d[k][j];
 for(int x1=1;x1<=n;x1++)
  for(int x2=x1+1;x2<=n;x2++)
  {
   ans=-1;
   for(int i=1;i<=n;i++)
    ans=max(ans,min(d[x1][i],d[x2][i]));
   if(ans<c)
   {
    a=x1;
    b=x2;
    c=ans;
   }
  }
 printf("%d %d",a,b);
 return 0;
}
