#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
struct dsu
{
 int fa[5005];
 void init(int n)
 {
  for(int i=1;i<=n;i++)
   fa[i]=i;
 }
 int find(int x)
 {
  return fa[x]==x?x:fa[x]=find(fa[x]);
 }
 bool merge(int x,int y)
 {
  x=find(x),y=find(y);
  if(x==y)return false;
  fa[y]=x;
  return true;
 }
}d;
int n,m,q;
int col[5005];
char s[5005];
bool flag;
bool res[5005][5005];
vector<int> e1[5005],e2[5005];
queue<pii> que;
void dfs(int u,int c)
{
 col[u]=c;
 for(auto v:e2[u])
  if(col[v]==col[u])flag=false;
  else if(col[v]==-1)
  {
   e1[u].push_back(v);
   e1[v].push_back(u);
   dfs(v,c^1);
  }
}
int main()
{
 ios::sync_with_stdio(false);
 memset(col,-1,sizeof(col));
 cin>>n>>m>>q;
 cin>>(s+1);
 d.init(n);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  cin>>u>>v;
  if(s[u]!=s[v])
  {
   if(d.merge(u,v))
   {
    e1[u].push_back(v);
    e1[v].push_back(u);
   }
  }
  else
  {
   e2[u].push_back(v);
   e2[v].push_back(u);  
  }
 }
 for(int i=1;i<=n;i++)
  if(col[i]==-1)
  {
   flag=true;
   dfs(i,0);
   if(!flag)e1[i].push_back(i);
  }
 for(int i=1;i<=n;i++)
  que.push({i,i}),res[i][i]=true;
 for(int u=1;u<=n;u++)
  for(auto v:e1[u])
  {
   if(v!=u&&s[u]==s[v])
    que.push({u,v}),res[u][v]=true;
  }
 while(!que.empty())
 {
  int x=que.front().first,y=que.front().second;
  que.pop();
  for(auto v1:e1[x])
   for(auto v2:e1[y])
    if(s[v1]==s[v2])
     if(!res[v1][v2])
      res[v1][v2]=true,que.push({v1,v2});
 }
 while(q--)
 {
  int x,y;
  cin>>x>>y;
  cout<<(res[x][y]?"YES":"NO")<<endl;
 }
 return 0;
}