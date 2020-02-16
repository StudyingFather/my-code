#include <stdio.h>
#include <string.h>
char s[15];
int t,num[15][15];
bool flag;
bool ok(int k,int x,int y)
{
 for(int i=1;i<=9;i++)
  if(num[x][i]==k)return false;
 for(int i=1;i<=9;i++)
  if(num[i][y]==k)return false;
 int u=x-(x-1)%3,v=y-(y-1)%3;
 for(int i=u;i<u+3;i++)
  for(int j=v;j<v+3;j++)
   if(num[i][j]==k)return false;
 return true;
}
void dfs(int x,int y)
{
 if(flag||x==10)
 {
  flag=true;
  return;
 }
 while(num[x][y])
 {
  if(y==9)
  {
   x++;
   y=1;
  }
  else y++;
  if(x==10)
  {
   flag=true;
   return;
  }
 }
 for(int k=1;k<=9;k++)
  if(ok(k,x,y))
  {
   num[x][y]=k;
   if(y==9)dfs(x+1,1);
   else dfs(x,y+1);
   if(flag)return;
   num[x][y]=0;
  }
}
int main()
{
 //freopen("sudoku.in","r",stdin);
 //freopen("sudoku.out","w",stdout);
 scanf("%d",&t);
 int ans=0;
 while(t--)
 {
  flag=false;
  memset(num,0,sizeof(num));
  for(int i=1;i<=9;i++)
  {
   scanf("%s",s);
   for(int j=0;j<=8;j++)
    num[i][j+1]=s[j]-'0';
  }
  dfs(1,1);
  ans+=num[1][1]*100+num[1][2]*10+num[1][3];
 }
 printf("%d\n",ans);
 return 0;
}
