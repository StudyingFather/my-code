// Problem : P3796 【模板】AC自动机（加强版）
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P3796
// Memory Limit : 128 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int sigma=26;
struct trie
{
 int cnt;
 int son[25005][sigma],fail[25005],end[25005],tot[155];
 void init()
 {
  cnt=0;
  memset(son,0,sizeof(son));
  memset(fail,0,sizeof(fail));
  memset(end,0,sizeof(end));
  memset(tot,0,sizeof(tot));
 }
 void insert(string s,int id)
 {
  int u=0;
  for(auto c:s)
  {
   if(!son[u][c-'a'])
    son[u][c-'a']=++cnt;
   u=son[u][c-'a'];
  }
  end[u]=id;
 }
 void build()
 {
  queue<int> q;
  for(int i=0;i<sigma;i++)
   if(son[0][i])q.push(son[0][i]);
  while(!q.empty())
  {
   int u=q.front();
   q.pop();
   for(int i=0;i<sigma;i++)
   {
    if(son[u][i])
     fail[son[u][i]]=son[fail[u]][i],q.push(son[u][i]);
    else
     son[u][i]=son[fail[u]][i];
   }
  }
 }
 int query(string s)
 {
  int u=0,ans=0;
  for(auto c:s)
  {
   u=son[u][c-'a'];
   for(int x=u;x;x=fail[x])
   {
    tot[end[x]]++;
    if(end[x])ans=max(ans,tot[end[x]]);
   }
  }
  return ans;
 }
}tr;
string s[155];
int main()
{
 int n;
 while(cin>>n&&n)
 {
  tr.init();
  string t;
  for(int i=1;i<=n;i++)
  {
   cin>>s[i];
   tr.insert(s[i],i);
  }
  tr.build();
  cin>>t;
  int ans=tr.query(t);
  cout<<ans<<endl;
  for(int i=1;i<=n;i++)
   if(ans==tr.tot[i])cout<<s[i]<<endl;
 }
 return 0;
}