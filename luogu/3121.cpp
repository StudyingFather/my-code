// Problem : P3121 [USACO15FEB]Censoring G
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P3121
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int sigma=26;
string s;
int tr[100005][sigma],fail[100005],v[100005],cnt;
int last[100005],pos[100005];
char sta[100005];
void insert(string s,int len)
{
 int u=0;
 for(auto c:s)
 {
  if(!tr[u][c-'a'])
   tr[u][c-'a']=++cnt;
  u=tr[u][c-'a'];
 }
 v[u]=len;
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
  {
   if(tr[u][i])
    fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
   else
    tr[u][i]=tr[fail[u]][i];
  }
 }
}
int main()
{
 cin>>s;
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  string t;
  cin>>t;
  insert(t,t.length());
 }
 build();
 int u=0,len=s.length();
 int top=0;
 for(int i=0;i<len;i++)
 {
  u=last[i]=tr[u][s[i]-'a'];
  sta[++top]=s[i],pos[top]=i;
  if(v[u])
  {
   top-=v[u];
   u=last[pos[top]];
  }
 }
 for(int i=1;i<=top;i++)
  cout<<s[pos[i]];
 cout<<endl;
 return 0;
}