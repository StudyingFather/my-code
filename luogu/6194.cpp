#include <cstdio>
char s[15][15];
int vis[15][15];
int main()
{
 for(int i=1;i<=8;i++)
  scanf("%s",s[i]+1);
 for(int i=1;i<=8;i++)
  for(int j=1;j<=8;j++)
   if(s[i][j]=='R')
   {
    vis[i][j]=1;
    for(int r=i-1;r>0&&s[r][j]=='.';r--)
     vis[r][j]=1;
    for(int r=i+1;r<=8&&s[r][j]=='.';r++)
     vis[r][j]=1;
    for(int c=j-1;c>0&&s[i][c]=='.';c--)
     vis[i][c]=1;
    for(int c=j+1;c<=8&&s[i][c]=='.';c++)
     vis[i][c]=1;
   }
   else if(s[i][j]=='B')
   {
    vis[i][j]=1;
    for(int r=i-1,c=j-1;r>0&&c>0&&s[r][c]=='.';r--,c--)
     vis[r][c]=1;
    for(int r=i+1,c=j+1;r<=8&&c<=8&&s[r][c]=='.';r++,c++)
     vis[r][c]=1;
    for(int r=i-1,c=j+1;r>0&&c<=8&&s[r][c]=='.';r--,c++)
     vis[r][c]=1;
    for(int r=i+1,c=j-1;r<=8&&c>0&&s[r][c]=='.';r++,c--)
     vis[r][c]=1;
   }
 for(int i=1;i<=8;i++)
 {
  for(int j=1;j<=8;j++)
   printf("%d",!vis[i][j]);
  puts("");
 }
 return 0;
}