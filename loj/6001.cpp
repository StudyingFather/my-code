#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[100005];
int n,m,s,t,cnt=1;
int head[105],dep[105],vis[105],cur[105];
vector<int> res1,res2;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool bfs()
{
 queue<int> q;
 memset(dep,INF,sizeof(dep));
 memset(vis,0,sizeof(vis));
 memcpy(cur,head,sizeof(head));
 dep[s]=0;
 vis[s]=1;
 q.push(s);
 while(!q.empty())
 {
  int p=q.front();
  q.pop();
  vis[p]=0;
  for(int i=head[p];i;i=e[i].next)
   if(dep[e[i].v]>dep[p]+1&&e[i].w)
   {
    dep[e[i].v]=dep[p]+1;
    if(!vis[e[i].v])
    {
     vis[e[i].v]=1;
     q.push(e[i].v);
    }
   }
 }
 if(dep[t]==INF)return 0;
 return 1;
}
int dfs(int p,int w)
{
 if(p==t)return w;
 int used=0;
 for(int i=cur[p];i;i=e[i].next)
 {
  cur[p]=i;
  if(dep[e[i].v]==dep[p]+1&&e[i].w)
  {
   int flow=dfs(e[i].v,min(w-used,e[i].w));
   if(flow)
   {
    used+=flow;
    e[i].w-=flow;
    e[i^1].w+=flow;
    if(used==w)break;
   }
  }
 }
 return used;
}
void dfs(int x)
{
 vis[x]=1;
 if(x==t)return;
 if(x<=n)res1.push_back(x);
 else if(x!=s)res2.push_back(x-n);
 for(int i=head[x];i;i=e[i].next)
 {
  int v=e[i].v;
  if(!vis[v]&&e[i].w)dfs(v);
 }
}
int main()
{
 int ans=0;
 cin>>n>>m;
 s=n+m+1,t=n+m+2;
 for(int i=1;i<=n;i++)
 {
  int c;
  cin>>c;
  ans+=c;
  addedge(s,i,c),addedge(i,s,0);
  string str;
  getline(cin,str);
  stringstream ss(str);
  int x;
  while(ss>>x)
   addedge(i,x+n,INF),addedge(x+n,i,0);
 }
 for(int i=1;i<=m;i++)
 {
  int c;
  cin>>c;
  addedge(i+n,t,c),addedge(t,i+n,0);
 }
 while(bfs())
  ans-=dfs(s,INF);
 dfs(s);
 sort(res1.begin(),res1.end());
 sort(res2.begin(),res2.end());
 for(auto x:res1)
  if(x==res1[0])cout<<x;
  else cout<<' '<<x;
 cout<<endl;
 for(auto x:res2)
  if(x==res2[0])cout<<x;
  else cout<<' '<<x;
 cout<<endl;
 cout<<ans<<endl;
 return 0;
}