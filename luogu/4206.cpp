// Problem : P4206 [NOI2005]聪聪与可可
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P4206
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int d[1005][1005],nxt[1005][1005],vis[1005];
double f[1005][1005];
vector<int> e[1005];
double dfs(int s,int t)
{
 if(s==t)return 0;
 else if(d[s][t]<=2)return 1;
 else if(f[s][t])return f[s][t];
 else
 {
  f[s][t]=1;
  int p=nxt[nxt[s][t]][t];
  for(auto v:e[t])
   f[s][t]+=dfs(p,v)/(1+e[t].size());
  f[s][t]+=dfs(p,t)/(1+e[t].size());
  return f[s][t];
 }
}
int main()
{
 int n,m,s,t;
 scanf("%d%d",&n,&m);
 scanf("%d%d",&s,&t);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  e[u].push_back(v);
  e[v].push_back(u);
 }
 memset(d,63,sizeof(d));
 memset(nxt,63,sizeof(nxt));
 queue<int> q;
 for(int s=1;s<=n;s++)
 {
  d[s][s]=0,vis[s]=true;
  q.push(s);
  while(!q.empty())
  {
   int u=q.front();
   q.pop();
   vis[u]=0;
   for(auto v:e[u])
   {
    if(d[s][v]>d[s][u]+1)
    {
     d[s][v]=d[s][u]+1;
     if(!vis[v])
      q.push(v),vis[v]=1;
    }
   }
  }
 }
 for(int u=1;u<=n;u++)
  for(auto v:e[u])
   for(int w=1;w<=n;w++)
    if(d[u][w]==d[v][w]+1)
     nxt[u][w]=min(nxt[u][w],v);
 printf("%.3lf\n",dfs(s,t));
 return 0;
}