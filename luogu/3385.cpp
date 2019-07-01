#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
struct edge
{
 int t,w,next;
}e[400005];
int head[20005],q[4000005],d[20005],vis[20005],vt[20005],cnt;
int n,m;
inline void insert(int s,int t,int w)
{
 e[++cnt].t=t;
 e[cnt].w=w;
 e[cnt].next=head[s];
 head[s]=cnt;
}
inline bool spfa()
{
 int l=0,r=1;
 d[1]=0;
 q[r]=1;
 while(l<r)
 {
  int h=q[++l];
  vis[h]=0;
  for(int i=head[h];~i;i=e[i].next)
  {
   if(d[h]+e[i].w<d[e[i].t])
   {
    vt[e[i].t]++;
    if(vt[e[i].t]>=n)return 1;
    d[e[i].t]=d[h]+e[i].w;
    if(!vis[e[i].t])
    {
     q[++r]=e[i].t;
     vis[e[i].t]=1;
    }
   }
  }
 }
 return 0;
}
inline void init()
{
 cnt=0;
 memset(q,0,sizeof(q));
 memset(e,0,sizeof(e));
 memset(head,-1,sizeof(head));
 memset(vis,0,sizeof(vis));
 vis[1]=1;
 memset(d,INF,sizeof(d));
 memset(vt,0,sizeof(vt));
}
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  init();
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
  {
   int a,b,w;
   scanf("%d%d%d",&a,&b,&w);
   insert(a,b,w);
   if(w>=0)insert(b,a,w);
  }
  if(spfa())puts("YE5");
  else puts("N0");
 }
 return 0;
}
