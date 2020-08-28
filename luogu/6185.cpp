// Problem : P6185 [NOI Online #1 提高组]序列（民间数据）
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P6185
// Memory Limit : 250 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> e[200005];
int a[200005],b[200005],c[200005],vis[200005];
int s[2];
bool flag;
void dfs(int u,int col)
{
 vis[u]=col;
 s[col]+=c[u];
 for(auto v:e[u])
  if(vis[v]==-1)
   dfs(v,col^1);
  else if(vis[u]==vis[v])
   flag=false;
}
int main()
{
 ios::sync_with_stdio(false);
 int t;
 cin>>t;
 while(t--)
 {
  memset(c,0,sizeof(c));
  memset(vis,-1,sizeof(vis));
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n+m;i++)
   e[i].clear();
  for(int i=1;i<=n;i++)
   cin>>a[i];
  for(int i=1;i<=n;i++)
   cin>>b[i];
  for(int i=1;i<=n;i++)
   c[i]=b[i]-a[i];
  int cnt=n;
  for(int i=1;i<=m;i++)
  {
   int t,u,v;
   cin>>t>>u>>v;
   if(t==2)
   {
    cnt++;
    e[u].push_back(cnt),e[cnt].push_back(u);
    e[v].push_back(cnt),e[cnt].push_back(v);
   }
   else
    e[u].push_back(v),e[v].push_back(u);
  }
  bool ans=true;
  for(int i=1;i<=n;i++)
   if(vis[i]==-1)
   {
    s[0]=s[1]=0;
    flag=true;
    dfs(i,0);
    if(!flag)ans&=((s[0]+s[1])%2==0);
    if(flag)ans&=(s[0]==s[1]);
   }
  if(ans)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
 }
 return 0;
}