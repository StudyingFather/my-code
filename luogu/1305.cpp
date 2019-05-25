#include <cstdio>
char s[35][5];
int n;
void dfs(char c)
{
 if(c!='*')
 {
  putchar(c);
  for(int i=1;i<=n;i++)
   if(s[i][0]==c)
   {
    dfs(s[i][1]);
    dfs(s[i][2]);
   }
 }
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%s",s[i]);
 dfs(s[1][0]);
 return 0;
}