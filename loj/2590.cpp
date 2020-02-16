#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
struct edge
{
 int t,next;
}e[1000010];
int g[100010],cnt,a1[100010],a2[100010],v[100010];
queue<int>qu;
void link(int s,int t)
{
 e[cnt].t=t;
 e[cnt].next=g[s];
 g[s]=cnt++;
}
void SPFA()
{
 memset(a2,-1,sizeof(a2));
 qu.push(1);
 while(!qu.empty())
 {
  int x=qu.front();
  qu.pop();
  v[x]=2;
  for(int i=g[x];i;i=e[i].next)
  {
   int t=e[i].t;
   if(a2[t]==-1||a2[t]<a1[t]-a1[x])
   {
   	v[t]=0;
	a2[t]=max(a1[t]-a1[x],0);
   }
   if(a2[t]<a2[x])
   {
    v[t]=0;
    a2[t]=max(a2[t],a2[x]);
   }
   if(v[t]==0)
   {
   	v[t]=1;
	qu.push(t);
   }
  }
 }
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d",&a1[i]);
 for(int i=0;i<m;i++)
 {
  int x,y,z;
  scanf("%d%d%d",&x,&y,&z);
  link(x,y);
  if(z==2)link(y,x);
 }
 SPFA();
 printf("%d",a2[n]);
 return 0;
}