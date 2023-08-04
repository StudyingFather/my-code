// Problem : C - Three Circuits
// Contest : AtCoder - AtCoder Grand Contest 032
// URL : https://atcoder.jp/contests/agc032/tasks/agc032_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <vector>
using namespace std;
vector<int> e[100005];
int p,q,vis[100005];
void dfs(int u)
{
 vis[u]=1;
 for(auto v:e[u])
  if(vis[v]==-1)
  {
   if(p)q=v;
   else p=v;
  }
  else if(!vis[v])dfs(v);
}
int main()
{
 ios::sync_with_stdio(false);
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=m;i++)
 {
  int u,v;
  cin>>u>>v;
  e[u].push_back(v);
  e[v].push_back(u);
 }
 int maxd=0,cnt=0;
 for(int i=1;i<=n;i++)
 {
  int t=e[i].size();
  if(t%2)
  {
   cout<<"No"<<endl;
   return 0;
  }
  if(t>maxd)
   maxd=t,cnt=1;
  else if(t==maxd)cnt++;
 }
 if(maxd>=6)
  cout<<"Yes"<<endl;
 else if(maxd==4)
 {
  if(cnt>=3)
   cout<<"Yes"<<endl;
  else if(cnt==1)
   cout<<"No"<<endl;
  else
  {
   for(int i=1;i<=n;i++)
    if(e[i].size()==4)vis[i]=-1;
   for(int i=1;i<=n;i++)
    if(!vis[i])
    {
     p=q=0;
     dfs(i);
     if(p==q)
     {
      cout<<"Yes"<<endl;
      return 0;
     }
    }
   cout<<"No"<<endl;
  }
 }
 else cout<<"No"<<endl;
 return 0;
}