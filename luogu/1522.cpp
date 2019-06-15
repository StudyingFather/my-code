#include <cstdio>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
struct point
{
 int x,y;
}p[155];
char s[155];
double f[155][155],dist[155];
double calc(int a,int b)
{
 return sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&p[i].x,&p[i].y);
 for(int i=1;i<=n;i++)
 {
  scanf("%s",s+1);
  for(int j=1;j<=n;j++)
   if(s[j]=='1')f[i][j]=calc(i,j);
   else if(i!=j)f[i][j]=INF;
 }
 for(int k=1;k<=n;k++)
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
 double mind1=0,mind2=INF;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   if(f[i][j]!=INF)
   {
    dist[i]=max(dist[i],f[i][j]);
    mind1=max(mind1,dist[i]);
   }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
   if(f[i][j]==INF)mind2=min(mind2,dist[i]+dist[j]+calc(i,j));
 printf("%.6lf\n",max(mind1,mind2));
 return 0;
}