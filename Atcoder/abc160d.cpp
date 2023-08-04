#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int vis[2005],ans[2005],t[2005];
vector<int> e[2005];
queue<int> q;
int main()
{
 int n,x,y;
 scanf("%d%d%d",&n,&x,&y);
 for(int i=1;i<n;i++)
 {
  e[i].push_back(i+1);
  e[i+1].push_back(i);
 }
 e[x].push_back(y);
 e[y].push_back(x);
 for(int i=1;i<=n;i++)
 {
  memset(vis,-1,sizeof(vis));
  vis[i]=0;
  q.push(i);
  while(!q.empty())
  {
   int u=q.front();
   q.pop();
   for(auto v:e[u])
    if(vis[v]==-1)
    {
     vis[v]=vis[u]+1;
     q.push(v);
    }
  }
  for(int i=1;i<=n;i++)
   t[vis[i]]++;
 }
 for(int i=1;i<n;i++)
  printf("%d\n",t[i]/2);
 return 0;
}