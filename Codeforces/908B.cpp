#include <stdio.h>
#include <string.h>
char map[55][55],order[105];
int n,m,sx,sy,ex,ey,len,ans,way[4],v[4];
void solve(int k)
{
 if(k==4)
 {
  int x=sx,y=sy;
  for(int i=0;;i++)
  {
   int action=way[order[i]-'0'];
   if(action==1)x--;
   else if(action==2)y--;
   else if(action==3)x++;
   else y++;
   if(x==0||y==0||x==n+1||y==m+1||map[x][y]=='#')return;
   if(map[x][y]=='E')
   {
   	ans++;
   	return;
   }
   if(i==len)i=0;
  }
 }
 else
  for(int i=1;i<=4;i++)
   if(!v[i])
   {
    v[i]=1;
    way[k]=i;
    solve(k+1);
    v[i]=0;
    way[k]=0;
   }
}
int main()
{
 scanf("%d%d",&n,&m);
 getchar();
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=m;j++)
  {
   scanf("%c",&map[i][j]);
   if(map[i][j]=='S')sx=i,sy=j;
   if(map[i][j]=='E')ex=i,ey=j;
  }
  getchar();
 }
 scanf("%s",order);
 len=strlen(order);
 solve(0);
 printf("%d",ans);
 return 0;
}
