#include <stdio.h>
#include <string.h>
int ans,vis[25],cyc[25],ma[25][25];
void dfs(int cur,int d)
{
 if(d==20)
 {
  if(!ma[cur][cyc[1]])return;
  printf("%d:  ",++ans);
  for(int i=1;i<=20;i++)
   printf("%d ",cyc[i]);
  printf("%d\n",cyc[1]);
  return;
 }
 for(int i=1;i<=20;i++)
  if(ma[cur][i]&&(!vis[i]))
  {
   cyc[d+1]=i;
   vis[i]=1;
   dfs(i,d+1);
   cyc[d+1]=0;
   vis[i]=0;
  }
}
int main()
{
 for(int i=1;i<=20;i++)
 {
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  ma[i][a]=ma[i][b]=ma[i][c]=1;
 }
 int m;
 while((~scanf("%d",&m))&&m)
 {
  memset(vis,0,sizeof(vis));
  memset(cyc,0,sizeof(cyc));
  ans=0;
  vis[m]=1;
  cyc[1]=m;
  dfs(m,1);
 }
}
