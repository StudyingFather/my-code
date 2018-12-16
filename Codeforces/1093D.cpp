#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#define MOD 998244353
using namespace std;
struct edge
{
 int v,next;
}e[300005];
long long head[300005],vis[300005],cnt,ans,totp;
inline void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
inline int bfs(int cur)
{
 int cntp=1;
 totp=1;
 queue<int> q;
 vis[cur]=0;
 q.push(cur);
 if(head[cur]==0)return -1;
 while(!q.empty())
 {
  cur=q.front();
  q.pop();
  for(int i=head[cur];i;i=e[i].next)
   if(vis[e[i].v]==-1)
   {
   	vis[e[i].v]=!vis[cur];
   	totp++;
	if(vis[e[i].v]==0)cntp++;
   	q.push(e[i].v);
   }
   else if(vis[e[i].v]==vis[cur])return 0;
 }
 return cntp;
}
inline long long fpow(long long a,long long b)
{
 long long ans=1;
 while(b>0)
 {
  if(b&1)ans=ans*a%MOD;
  a=a*a%MOD;
  b>>=1;
 }
 return ans;
}
int main()
{
 ios::sync_with_stdio(false);
 cin.tie(0),cout.tie(0);
 int t;
 cin>>t;
 while(t--)
 {
  memset(e,0,sizeof(e));
  memset(head,0,sizeof(head));
  memset(vis,-1,sizeof(vis));
  cnt=0,ans=1;
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
   int u,v;
   cin>>u>>v;
   addedge(u,v);
   addedge(v,u);
  }
  for(int i=1;i<=n;i++)
   if(vis[i]==-1)
   {
	int cntp=bfs(i);
   	if(cntp==0)
	{
	 ans=0;
   	 break;
	}
   	else if(cntp==-1)
	{
	 ans*=3;
	 if(ans>=MOD)ans%=MOD;
	 continue;
	}
   	else ans*=(fpow(2,cntp)+fpow(2,totp-cntp))%MOD,ans%=MOD;
   }
  cout<<ans<<endl;
 }
 return 0;
}
