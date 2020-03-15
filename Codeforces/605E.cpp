#include <cstdio>
using namespace std;
double p[1005][1005],q[1005],dis[1005];
int vis[1005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
  {
   scanf("%lf",&p[i][j]);
   p[i][j]/=100;
  }
 for(int i=1;i<=n;i++)
 {
  dis[i]=1;
  q[i]=1-p[i][n];
 }
 dis[n]=0,vis[n]=1;
 for(int i=1;i<=n;i++)
 {
  int u;
  double mind=1e50;
  for(int j=1;j<=n;j++)
  {
   if(!vis[j]&&dis[j]/(1-q[j])<mind)
    mind=dis[j]/(1-q[j]),u=j;
  }
  vis[u]=1;
  if(u==1)break;
  for(int v=1;v<=n;v++)
  {
   dis[v]+=dis[u]/(1-q[u])*p[v][u]*q[v];
   q[v]*=1-p[v][u];
  }
 }
 printf("%.10lf\n",dis[1]/(1-q[1]));
 return 0;
}