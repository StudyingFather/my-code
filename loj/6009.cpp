#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct fix
{
 int t,b1,b2,f1,f2;
}a[105];
int dis[4000005],vis[4000005];
char s[25];
queue<int> q;
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  scanf("%d",&a[i].t);
  scanf("%s",s);
  for(int j=0;j<n;j++)
   if(s[j]=='+')a[i].b1|=(1<<j);
   else if(s[j]=='-')a[i].b2|=(1<<j);
  scanf("%s",s);
  for(int j=0;j<n;j++)
   if(s[j]=='-')a[i].f1|=(1<<j);
   else if(s[j]=='+')a[i].f2|=(1<<j);
 }
 memset(dis,INF,sizeof(dis));
 dis[(1<<n)-1]=0,vis[(1<<n)-1]=1;
 q.push((1<<n)-1);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  vis[u]=0;
  for(int i=1;i<=m;i++)
   if((u&a[i].b1)==a[i].b1&&(u&a[i].b2)==0)
   {
    int v=(u&(~a[i].f1))|(a[i].f2);
    if(dis[v]>dis[u]+a[i].t)
    {
     dis[v]=dis[u]+a[i].t;
     if(!vis[v])
     {
      vis[v]=1;
      q.push(v);
     }
    }
   }
 }
 if(dis[0]==INF)puts("0");
 else printf("%d\n",dis[0]);
 return 0;
}