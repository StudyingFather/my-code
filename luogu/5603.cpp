/*
 Name: luogu P5603
 Author: StudyingFather
 Date: 2019/10/29 01:00
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
struct edge
{
 int v,next;
}e[500005];
int head[500005],t[500005],n,m,cnt;
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
namespace p1
{
 int in[500005];
 priority_queue<int,vector<int>,greater<int> >q;
 void solve()
 {
  memcpy(in,t,sizeof(t));
  for(int i=1;i<=n;i++)
   if(!in[i])q.push(i);
  int maxp=0,ans=0;
  while(!q.empty())
  {
   int u=q.top();
   q.pop();
   if(u>maxp)ans++,maxp=u;
   for(int i=head[u];i;i=e[i].next)
   {
    int v=e[i].v;
    in[v]--;
    if(!in[v])q.push(v);
   }
  }
  printf("%d\n",ans);
 }
}
namespace p2
{
 int in[500005];
 set<int> s;
 void solve()
 {
  memcpy(in,t,sizeof(t));
  for(int i=1;i<=n;i++)
   if(!in[i])s.insert(i);
  int maxp=0,ans=0;
  while(!s.empty())
  {
   int u;
   if(maxp>*s.begin())
   {
    u=*s.begin();
    s.erase(u);
   }
   else
   {
    auto it=s.end();
    it--;
    u=*it;
    s.erase(u);
   }
   if(u>maxp)ans++,maxp=u;
   for(int i=head[u];i;i=e[i].next)
   {
    int v=e[i].v;
    in[v]--;
    if(!in[v])s.insert(v);
   }
  }
  printf("%d\n",ans);
 }
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  addedge(u,v);
  t[v]++;
 }
 p1::solve();
 p2::solve();
 return 0;
}