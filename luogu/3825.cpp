// Problem: P3825 [NOI2017]游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3825
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct rule
{
 int i,j;
 char hi[5],hj[5];
}a[100005];
int dfn[100005],low[100005],vis[100005],col[100005],colc,cnt;
char S[50005],ns[50005];
const char ma[5][5]={"BC","AC","AB"};
int n,d,m;
vector<int> pos;
vector<int> e[100005];
stack<int> s;
void dfs(int u)
{
 dfn[u]=low[u]=++cnt;
 vis[u]=1,s.push(u);
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
  colc++;
  while(!s.empty())
  {
   int x=s.top();
   s.pop();
   col[x]=colc,vis[x]=0;
   if(x==u)break;
  }
 }
}
int main()
{
 cin>>n>>d;
 cin>>(S+1);
 cin>>m;
 for(int x=1;x<=m;x++)
  cin>>a[x].i>>a[x].hi>>a[x].j>>a[x].hj;
 memcpy(ns,S,sizeof(S));
 for(int i=1;i<=n;i++)
  if(S[i]=='x')pos.push_back(i);
 for(int s=0;s<(1<<d);s++)
 {
  for(int i=1;i<=2*n;i++)
   e[i].clear();
  memset(dfn,0,sizeof(dfn));
  memset(low,0,sizeof(low));
  cnt=colc=0;
  for(int i=0;i<d;i++)
   if(s&(1<<i))ns[pos[i]]='a';
   else ns[pos[i]]='b';
  for(int x=1;x<=m;x++)
  {
   int i=a[x].i,j=a[x].j;
   int mai=ns[i]-'a',maj=ns[j]-'a';
   int u1=i+n*(a[x].hi[0]!=ma[mai][0]),v1=j+n*(a[x].hj[0]!=ma[maj][0]);
   int u2=(u1>n?u1-n:u1+n),v2=(v1>n?v1-n:v1+n);
   if(a[x].hi[0]-'A'==mai)continue;
   if(a[x].hj[0]-'A'==maj)
    e[u1].push_back(u2);
   else
   {
    e[u1].push_back(v1);
    e[v2].push_back(u2);
   }
  }
  for(int i=1;i<=2*n;i++)
   if(!dfn[i])dfs(i);
  bool flag=true;
  for(int i=1;i<=n;i++)
   if(col[i]==col[i+n])flag=false;
  if(flag)
  {
   for(int i=1;i<=n;i++)
    if(col[i]<col[i+n])
    {
     if(ns[i]=='a')cout<<'B';
     else cout<<'A';
    }
    else
    {
     if(ns[i]!='c')cout<<'C';
     else cout<<'B';
    }
   return 0;
  }
 }
 cout<<-1<<endl;
 return 0;
}