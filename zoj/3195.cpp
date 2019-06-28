#include <cstdio>
#include <cstring>
using namespace std;
int n,ask,a,b,c,u,v,w;
int ans[300005];
bool fir;
struct edge
{
 int to,next,val;
}e[100005],q[600005];
int ecnt,qcnt,ehead[50005],qhead[50005];
inline void addedge(int now,int to,int val,int &ecnt,edge e[],int ehead[])
{
 e[++ecnt].to=to;
 e[ecnt].val=val;
 e[ecnt].next=ehead[now];
 ehead[now]=ecnt;
}
int fa[50005];
int find_set(int now)
{
 return fa[now]==now?now:fa[now]=find_set(fa[now]);
} 
int vis[50005],dis[50005];
void tarjan(int now)
{
 vis[now]=1;
 for(int i=qhead[now];i!=-1;i=q[i].next)
 {
  if(ans[q[i].val]!=-1)continue;
  if(vis[q[i].to]==0)continue;
  if(vis[q[i].to]==1)ans[q[i].val]=dis[now]-dis[q[i].to];
  if(vis[q[i].to]==2)ans[q[i].val]=dis[now]+dis[q[i].to]-2*dis[find_set(q[i].to)];
 }
 for(int i=ehead[now];i!=-1;i=e[i].next)
  if(vis[e[i].to]==0)
  {
   dis[e[i].to]=dis[now]+e[i].val;
   tarjan(e[i].to);
   vis[e[i].to]=2;
   fa[e[i].to]=now;
  } 
}
inline void tarjan_run()
{
 for(int i=1;i<=n;i++)
  if(vis[i]==-1) tarjan(i);
}
int main()
{
 while(scanf("%d",&n)!=EOF)
 {
  ecnt=qcnt=0;
  for(int i=0;i<=n;i++)
   fa[i]=i;
  memset(ehead,-1,sizeof(ehead));
  memset(qhead,-1,sizeof(qhead));
  memset(ans,-1,sizeof(ans));
  memset(vis,0,sizeof(vis));
  for(int i=1;i<n;i++)
  {
   scanf("%d%d%d",&u,&v,&w); 
   addedge(u,v,w,ecnt,e,ehead);
   addedge(v,u,w,ecnt,e,ehead);
  } 
  scanf("%d",&ask);
  for(int i=1;i<=ask;i++)
  {
   scanf("%d%d%d",&a,&b,&c); 
   addedge(a,b,(i-1)*3+1,qcnt,q,qhead);
   addedge(b,a,(i-1)*3+1,qcnt,q,qhead);
   addedge(a,c,(i-1)*3+2,qcnt,q,qhead);
   addedge(c,a,(i-1)*3+2,qcnt,q,qhead);
   addedge(b,c,(i-1)*3+3,qcnt,q,qhead);
   addedge(c,b,(i-1)*3+3,qcnt,q,qhead);
  }
  tarjan(0);
  if(fir)printf("\n");
  for(int i=1;i<=ask;i++)
   printf("%d\n",(ans[(i-1)*3+1]+ans[(i-1)*3+2]+ans[(i-1)*3+3])/2);
  fir=true;
 }
 return 0;
}
