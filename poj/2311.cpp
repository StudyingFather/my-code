#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
int sg[205][205];
int calc(int n,int m)
{
 if(sg[n][m]!=-1)return sg[n][m];
 int vis[1005];
 memset(vis,0,sizeof(vis));
 for(int i=2;i<=n-i;i++)
  vis[calc(i,m)^calc(n-i,m)]=1;
 for(int i=2;i<=m-i;i++)
  vis[calc(n,i)^calc(n,m-i)]=1;
 for(int i=0;;i++)
  if(vis[i]==0)return sg[n][m]=i;
}
int main()
{
 int n,m;
 memset(sg,-1,sizeof(sg));
 while(scanf("%d%d",&n,&m)!=EOF)
  if(calc(n,m))puts("WIN");
  else puts("LOSE");
 return 0;
}
