// Problem : P1954 [NOI2010]航空管制
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P1954
// Memory Limit : 500 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int,int> pii;
int k[2005],t[2005],ot[2005];
priority_queue<pii> q;
stack<int> ans;
vector<int> e[2005];
int main()
{
 ios::sync_with_stdio(false);
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  cin>>k[i];
 for(int i=1;i<=m;i++)
 {
  int u,v;
  cin>>u>>v;
  e[v].push_back(u);
  ot[u]++;
 }
 memcpy(t,ot,sizeof(t));
 for(int i=1;i<=n;i++)
  if(!t[i])
   q.push(make_pair(k[i],i));
 while(!q.empty())
 {
  int u=q.top().second;
  q.pop();
  ans.push(u);
  for(auto v:e[u])
  {
   t[v]--;
   if(!t[v])q.push(make_pair(k[v],v));
  }
 }
 while(!ans.empty())
  cout<<ans.top()<<' ',ans.pop();
 cout<<endl;
 for(int x=1;x<=n;x++)
 {
  memcpy(t,ot,sizeof(t));
  while(!q.empty())
   q.pop();
  int mink=n;
  for(int i=1;i<=n;i++)
   if(!t[i])
    q.push(make_pair(k[i],i));
  while(!q.empty())
  {
   int u=q.top().second;
   q.pop();
   if(u==x)continue;
   if(k[u]<mink)
    break;
   mink--;
   for(auto v:e[u])
   {
    t[v]--;
    if(!t[v])q.push(make_pair(k[v],v));
   }
  }
  cout<<mink<<' ';
 }
 return 0;
}