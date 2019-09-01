/*
 Name: loj 3052
 Author: StudyingFather
 Date: 2019/08/07 19:14
 Website: https://studyingfather.com
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct edge
{
 int v,next;
}e[200005];
int head[200005],m[200005],cnt;
priority_queue<int> q[200005];
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void merge(int x,int y)
{
 if(q[x].size()<q[y].size())swap(q[x],q[y]);
 priority_queue<int> tmp;
 while(!q[y].empty())
 {
  tmp.push(max(q[x].top(),q[y].top()));
  q[x].pop(),q[y].pop();
 }
 while(!tmp.empty())
 {
  q[x].push(tmp.top());
  tmp.pop();
 }
}
void dfs(int u)
{
 for(int i=head[u];i;i=e[i].next)
  dfs(e[i].v),merge(u,e[i].v);
 q[u].push(m[u]);
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>m[i];
 for(int i=2;i<=n;i++)
 {
  int f;
  cin>>f;
  addedge(f,i);
 }
 dfs(1);
 long long ans=0;
 while(!q[1].empty())
  ans+=q[1].top(),q[1].pop();
 cout<<ans<<endl;
 return 0;
}