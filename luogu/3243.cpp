// Problem : P3243 [HNOI2015]菜肴制作
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P3243
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int> q;
vector<int> ans,e[100005];
int t[100005];
int main()
{
 int T;
 cin>>T;
 while(T--)
 {
  memset(t,0,sizeof(t));
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
   e[i].clear();
  for(int i=1;i<=m;i++)
  {
   int u,v;
   cin>>u>>v;
   e[v].push_back(u);
   t[u]++;
  }
  for(int i=1;i<=n;i++)
   if(!t[i])q.push(i);
  ans.clear();
  while(!q.empty())
  {
   int u=q.top();
   q.pop();
   ans.push_back(u);
   for(auto v:e[u])
   {
    t[v]--;
    if(!t[v])q.push(v);
   }
  }
  if(ans.size()!=n)cout<<"Impossible!"<<endl;
  else
  {
   for(int i=n-1;i>=0;i--)
    cout<<ans[i]<<' ';
   cout<<endl;
  }
 }
 return 0;
}