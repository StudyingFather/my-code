#include <stdio.h>
char s[105][105];
int cnt,vis[105][105],n,m;
void dfs(int x,int y,int cur)
{
 vis[x][y]=cur;
 if((!vis[x-1][y-1])&&x!=1&&y!=1&&s[x-1][y-1]=='W')dfs(x-1,y-1,cur);
 if((!vis[x-1][y])&&x!=1&&s[x-1][y]=='W')dfs(x-1,y,cur);
 if((!vis[x-1][y+1])&&x!=1&&y!=m&&s[x-1][y+1]=='W')dfs(x-1,y+1,cur);
 if((!vis[x][y-1])&&y!=1&&s[x][y-1]=='W')dfs(x,y-1,cur);
 if((!vis[x][y+1])&&y!=m&&s[x][y+1]=='W')dfs(x,y+1,cur);
 if((!vis[x+1][y-1])&&x!=n&&y!=1&&s[x+1][y-1]=='W')dfs(x+1,y-1,cur);
 if((!vis[x+1][y])&&x!=n&&s[x+1][y]=='W')dfs(x+1,y,cur);
 if((!vis[x+1][y+1])&&x!=n&&y!=m&&s[x+1][y+1]=='W')dfs(x+1,y+1,cur);
 return;
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%s",s[i]+1);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   if((!vis[i][j])&&s[i][j]=='W')cnt++,dfs(i,j,cnt);
 printf("%d\n",cnt);
 return 0;
}
