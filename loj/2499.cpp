#include <cstdio>
#include <algorithm>
#define MOD 10007
using namespace std;
struct edge
{
 int v,next;
}e[400005];
int w[200005],head[200005],cnt;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<n;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v);
  addedge(v,u);
 }
 for(int i=1;i<=n;i++)
  scanf("%d",&w[i]);
 int ans=0,maxx=0;
 for(int u=1;u<=n;u++)
 {
  int max1=0,max2=0,sum1=0,sum2=0;
  for(int i=head[u];i;i=e[i].next)
  {
   if(w[e[i].v]>max1)max2=max1,max1=w[e[i].v];
   else if(w[e[i].v]>max2)max2=w[e[i].v];
   sum1=(sum1+w[e[i].v])%MOD;
   sum2=(sum2+w[e[i].v]*w[e[i].v])%MOD;
  }
  ans=((ans+sum1*sum1-sum2)%MOD+MOD)%MOD;
  maxx=max(maxx,max1*max2);
 }
 printf("%d %d\n",maxx,ans);
 return 0;
}