// Problem : P5468 [NOI2019]回家路线
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P5468
// Memory Limit : 500 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
struct edge
{
 int v,p,q;
 bool operator<(const edge&a)const
 {
  return p<a.p||(p==a.p&&q<a.q);
 }
};
vector<edge> e[100005];
queue<pair<int,int> > q;
int dis[100005][1005];
bool vis[100005][1005];
int main()
{
 int n,m,a,b,c;
 scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
 for(int i=1;i<=m;i++)
 {
  int x,y,p,q;
  scanf("%d%d%d%d",&x,&y,&p,&q);
  e[x].push_back({y,p,q});
 }
 for(int i=1;i<=n;i++)
  sort(e[i].begin(),e[i].end());
 memset(dis,127,sizeof(dis));
 dis[1][0]=0;
 q.push(make_pair(1,0));
 while(!q.empty())
 {
  int u=q.front().first,t=q.front().second;
  q.pop();
  vis[u][t]=0;
  auto sta=lower_bound(e[u].begin(),e[u].end(),(edge){0,t,0});
  for(auto it=sta;it!=e[u].end();it++)
  {
   int v=it->v,vp=it->p,vq=it->q,d=vp-t;
   if(vp<t)continue;
   if(dis[v][vq]>dis[u][t]+a*d*d+b*d+c)
   {
    dis[v][vq]=dis[u][t]+a*d*d+b*d+c;
    if(!vis[v][vq])
    {
     q.push(make_pair(v,vq));
     vis[v][vq]=1;
    }
   }
  }
 }
 int ans=2147483647;
 for(int i=0;i<=1000;i++)
  ans=min(ans,dis[n][i]+i);
 printf("%d\n",ans);
 return 0;
}