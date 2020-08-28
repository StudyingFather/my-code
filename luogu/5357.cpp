// Problem : P5357 【模板】AC自动机（二次加强版）
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P5357
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int sigma=26;
int tr[200005][sigma],ed[200005],fail[200005],tot[200005],cnt;
vector<int> e[200005];
void insert(string s,int id)
{
 int u=0;
 for(auto c:s)
 {
  if(!tr[u][c-'a'])
   tr[u][c-'a']=++cnt;
  u=tr[u][c-'a'];
 }
 ed[id]=u;
}
void build()
{
 queue<int> q;
 for(int i=0;i<sigma;i++)
  if(tr[0][i])q.push(tr[0][i]);
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  for(int i=0;i<sigma;i++)
   if(tr[u][i])
    fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
   else
    tr[u][i]=tr[fail[u]][i];
 }
}
void query(string s)
{
 int u=0;
 for(auto c:s)
 {
  u=tr[u][c-'a'];
  tot[u]++;
 }
}
void dfs(int u)
{
 for(auto v:e[u])
 {
  dfs(v);
  tot[u]+=tot[v];
 }
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  string s;
  cin>>s;
  insert(s,i);
 }
 build();
 string s;
 cin>>s;
 query(s);
 for(int i=1;i<=cnt;i++)
  e[fail[i]].push_back(i);
 dfs(0);
 for(int i=1;i<=n;i++)
  cout<<tot[ed[i]]<<endl;
 return 0;
}