#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int t[505],vis[505],f[505][505];
queue<int> q;
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int id,m;
  scanf("%d%d",&id,&m);
  vis[id]=1;
  for(int j=1;j<=m;j++)
  {
   int x;
   scanf("%d",&x);
   f[id][x]=1;
   t[x]++;
  }
 }
 for(int i=0;i<=500;i++)
  if((!t[i])&&vis[i])q.push(i);
 while(ans<n)
 {
  if(q.empty())
  {
   printf("%d\n",n-ans);
   return 0;
  }
  int u=q.front();
  q.pop();
  for(int i=0;i<=500;i++)
   if(f[u][i]&&vis[i])
   {
    t[i]--;
    if(!t[i])q.push(i);
   }
  ans++;
 }
 puts("YES");
 return 0;
}