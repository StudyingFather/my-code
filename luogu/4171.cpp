// Problem : P4171 [JSOI2010]满汉全席
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P4171
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int,int> pii;
char s1[15],s2[15];
vector<int> e[205];
stack<int> s;
int dfn[205],low[205],col[205],vis[205];
int cnt,coln;
pii split(char* s)
{
 int op=(s[0]=='m');
 int num=0;
 for(int i=1;s[i];i++)
  num=num*10+s[i]-'0';
 return make_pair(op,num);
}
void dfs(int u)
{
 dfn[u]=low[u]=++cnt;
 s.push(u),vis[u]=1;
 for(auto v:e[u])
  if(!dfn[v])
   dfs(v),low[u]=min(low[u],low[v]);
  else if(vis[v])
   low[u]=min(low[u],dfn[v]);
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
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=2*n;i++)
   e[i].clear();
  memset(dfn,0,sizeof(dfn));
  memset(low,0,sizeof(low));
  memset(col,0,sizeof(col));
  coln=cnt=0;
  for(int i=1;i<=m;i++)
  {
   scanf("%s%s",s1,s2);
   auto u=split(s1),v=split(s2);
   e[(!u.first)*n+u.second].push_back(v.first*n+v.second);
   e[(!v.first)*n+v.second].push_back(u.first*n+u.second);
  }
  for(int i=1;i<=2*n;i++)
   if(!dfn[i])dfs(i);
  bool ans=true;
  for(int i=1;i<=n;i++)
   ans&=(col[i]!=col[i+n]);
  puts(ans?"GOOD":"BAD");
 }
 return 0;
}