#include <cstdio>
#include <algorithm>
using namespace std;
int vis[5000005],ans;
int t,a,b;
void dfs(int x,int y)
{
 if(vis[x])return;
 vis[x]=1;
 ans=max(x,ans);
 if(x+a<=t)dfs(x+a,y);
 if(x+b<=t)dfs(x+b,y);
 if(!y)dfs(x/2,1);
}
int main()
{
 scanf("%d%d%d",&t,&a,&b);
 dfs(0,0);
 printf("%d\n",ans);
 return 0;
}
