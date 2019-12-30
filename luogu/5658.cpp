#include <iostream>
#include <stack>
using namespace std;
struct edge
{
 int v,next;
}e[500005];
long long sum[500005],res[500005];
char s[500005];
int head[500005],fa[500005],cnt;
stack<int> sta;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int u)
{
 int p=0;
 if(s[u]==')')
 {
  if(!sta.empty())
  {
   p=sta.top();
   sta.pop();
   res[u]=res[fa[p]]+1;
  }
 }
 else sta.push(u);
 sum[u]=sum[fa[u]]+res[u];
 for(int i=head[u];i;i=e[i].next)
  dfs(e[i].v);
 if(p)sta.push(p);
 else if(!sta.empty())sta.pop();
}
int main()
{
 int n;
 cin>>n;
 cin>>(s+1);
 for(int i=2;i<=n;i++)
 {
  cin>>fa[i];
  addedge(fa[i],i);
 }
 dfs(1);
 long long ans=0;
 for(int i=1;i<=n;i++)
  ans^=(sum[i]*i);
 cout<<ans<<endl;
 return 0;
}