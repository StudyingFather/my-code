// Problem : P4782 【模板】2-SAT 问题
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P4782
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
vector<int> e[2000005];
int dfn[2000005],low[2000005],col[2000005];
int vis[2000005];
int cnt,coln;
stack<int> s;
void dfs(int u)
{
 dfn[u]=low[u]=++cnt;
 s.push(u),vis[u]=1;
 for(auto v:e[u])
 {
  if(!dfn[v])
  {
   dfs(v);
   low[u]=min(low[u],low[v]);
  }
  else if(vis[v])
   low[u]=min(low[u],dfn[v]);
 }
 if(dfn[u]==low[u])
 {
  coln++;
  while(!s.empty())
  {
   int x=s.top();
   s.pop();
   col[x]=coln,vis[x]=0;
   if(x==u)break;
  }
 }
}
int main()
{
 ios::sync_with_stdio(false);
 int n,m;
 cin>>n>>m;
 while(m--)
 {
  int x,vx,y,vy;
  cin>>x>>vx>>y>>vy;
  if(vx&&vy)
  {
   e[x+n].push_back(y);
   e[y+n].push_back(x);
  }
  else if(!vx&&!vy)
  {
   e[x].push_back(y+n);
   e[y].push_back(x+n);
  }
  else if(vx&&!vy)
  {
   e[x+n].push_back(y+n);
   e[y].push_back(x);
  }
  else//!vx&&vy
  {
   e[x].push_back(y);
   e[y+n].push_back(x+n);
  }
 }
 for(int i=1;i<=2*n;i++)
  if(!dfn[i])dfs(i);
 for(int i=1;i<=n;i++)
  if(col[i]==col[i+n])
  {
   cout<<"IMPOSSIBLE"<<endl;
   return 0;
  }
 cout<<"POSSIBLE"<<endl;
 for(int i=1;i<=n;i++)
  cout<<(col[i]<col[i+n])<<' ';
 return 0;
}