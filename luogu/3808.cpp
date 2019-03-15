#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct AC_Automaton
{
 int fail,vis[26],end;
}tr[1000005];
char s[1000005],t[1000005];
int cnt;
void build()
{
 int cur=0,len=strlen(s);
 for(int i=0;i<len;i++)
 {
  if(!tr[cur].vis[s[i]-'a'])tr[cur].vis[s[i]-'a']=++cnt;
  cur=tr[cur].vis[s[i]-'a'];
 }
 tr[cur].end++;
}
void get_fail()
{
 queue<int> q;
 for(int i=0;i<26;i++)
  if(tr[0].vis[i]!=0)
  {
   tr[tr[0].vis[i]].fail=0;
   q.push(tr[0].vis[i]);
  }
 while(!q.empty())
 {
  int cur=q.front();
  q.pop();
  for(int i=0;i<26;i++)
   if(tr[cur].vis[i])
   {
    tr[tr[cur].vis[i]].fail=tr[tr[cur].fail].vis[i];
    q.push(tr[cur].vis[i]);
   }
   else tr[cur].vis[i]=tr[tr[cur].fail].vis[i];
 }
}
int query()
{
 int len=strlen(t);
 int cur=0,ans=0;
 for(int i=0;i<len;i++)
 {
  cur=tr[cur].vis[t[i]-'a'];
  for(int j=cur;~tr[j].end;j=tr[j].fail)
   ans+=tr[j].end,tr[j].end=-1;
 }
 return ans;
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%s",s);
  build();
 }
 tr[0].fail=0;
 get_fail();
 scanf("%s",t);
 printf("%d\n",query());
 return 0;
}