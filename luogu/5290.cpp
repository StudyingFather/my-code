/*
 Name: luogu P5290
 Author: StudyingFather
 Date: 2019/08/05 17:03
 Website: https://studyingfather.com
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int m[200005],cnt;
vector<int> e[200005];
priority_queue<int> q[200005];
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
 int siz=e[u].size();
 for(int i=0;i<siz;i++)
  dfs(e[u][i]),merge(u,e[u][i]);
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
  e[f].push_back(i);
 }
 dfs(1);
 long long ans=0;
 while(!q[1].empty())
  ans+=q[1].top(),q[1].pop();
 cout<<ans<<endl;
 return 0;
}