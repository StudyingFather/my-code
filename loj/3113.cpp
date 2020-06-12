#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct node
{
 int x,y;
 bool operator<(const node&a)const
 {
  return y>a.y;
 }
};
vector<int> e[10005];
int t[10005],t1[10005],t2[10005],vis[10005];
int ord[10005],res[10005],cnt;
priority_queue<node> q;
int main()
{
 ios::sync_with_stdio(false);
 int T;
 cin>>T;
 while(T--)
 {
  int n,m;
  int ansp=0,ansq=0,pos=0;
  cnt=0;
  cin>>n>>m;
  memset(t,0,sizeof(t));
  for(int i=1;i<=n;i++)
   vector<int>().swap(e[i]);
  for(int i=1;i<=m;i++)
  {
   int u,v;
   cin>>u>>v;
   e[u].push_back(v);
   e[v].push_back(u);
   t[u]++,t[v]++;
  }
  memcpy(t1,t,sizeof(t));
  memcpy(t2,t,sizeof(t));
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=n;i++)
   q.push({i,t[i]});
  ansp=q.top().y;
  while(!q.empty())
  {
   int u=q.top().x;
   q.pop();
   if(vis[u])continue;
   ord[++cnt]=u,vis[u]=1;
   int rp=q.top().y;
   if(rp>ansp)
    ansp=rp,pos=cnt;
   for(auto v:e[u])
   {
    t1[v]--;
    q.push({v,t1[v]});
   }
  }
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=n;i++)
   q.push({i,t[i]});
  while(!q.empty())
  {
   int u=q.top().x;
   q.pop();
   if(vis[u])continue;
   res[++ansq]=u,vis[u]=1;
   for(auto v:e[u])
    vis[v]=1;
  }
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=pos;i++)
   vis[ord[i]]=1;
  cout<<n-pos<<' ';
  for(int i=1;i<=n;i++)
   if(!vis[i])cout<<i<<' ';
  cout<<endl;
  cout<<ansq<<' ';
  for(int i=1;i<=ansq;i++)
   cout<<res[i]<<' ';
  cout<<endl;
 }
 return 0;
}