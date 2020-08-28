// Problem: P3376 【模板】网络最大流
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3376
// Memory Limit: 128 MB
// Time Limit: 300 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
struct graph
{
 struct edge
 {
  int v,w,next;
 }e[10005];
 vector<int> e1[205];
 int head[205],cur[205],cnt=1;
 int dep[205],tot[205];
 int n,m,s,t;
 void init(int n,int m,int s,int t)
 {
  this->n=n,this->m=m,this->s=s,this->t=t;
 }
 void add(int u,int v,int w)
 {
  addedge(u,v,w),addedge(v,u,0);
  e1[v].push_back(u);
 }
 void addedge(int u,int v,int w)
 {
  e[++cnt].v=v;
  e[cnt].w=w;
  e[cnt].next=head[u];
  head[u]=cnt;
 }
 void bfs()
 {
  queue<int> q;
  memset(dep,63,sizeof(dep));
  dep[t]=0;
  tot[0]=1;
  q.push(t);
  while(!q.empty())
  {
   int u=q.front();
   q.pop();
   for(auto v:e1[u])
    if(dep[v]==INF)
    {
     tot[dep[v]=dep[u]+1]++;
     q.push(v);
    }
  }
 }
 int dfs(int u,int w)
 {
  if(u==t)return w;
  int used=0;
  for(int i=cur[u];i;i=e[i].next)
  {
   int v=e[i].v;
   if(e[i].w&&dep[u]==dep[v]+1)
   {
    int flow=dfs(v,min(w-used,e[i].w));
    e[i].w-=flow;
    e[i^1].w+=flow;
    used+=flow;
    if(w==used)return w;
   }
  }
  tot[dep[u]]--;
  if(!tot[dep[u]])tot[s]=n;
  dep[u]=n;
  for(int i=head[u];i;i=e[i].next)
   if(e[i].w)dep[u]=min(dep[u],dep[e[i].v]+1);
  tot[dep[u]]++;
  return used;
 }
 long long maxflow()
 {
  bfs();
  long long ans=0;
  while(dep[s]<n)
  {
   memcpy(cur,head,sizeof(head));
   ans+=dfs(s,INF);
  }
  return ans;
 }
}g;
int main()
{
 int n,m,s,t;
 cin>>n>>m>>s>>t;
 g.init(n,m,s,t);
 for(int i=1;i<=m;i++)
 {
  int u,v,w;
  cin>>u>>v>>w;
  g.add(u,v,w);
 }
 cout<<g.maxflow()<<endl;
 return 0;
}