#include <cstdio>
#include <cstring>
char a[35],b[35];
int len;
void dfs(int l1,int r1,int l2,int r2)
{
 for(int i=0;i<len;i++)
  if(a[i]==b[r2])
  {
   putchar(b[r2]);
   if(i>l1)dfs(l1,i-1,l2,r2-r1+i-1);
   if(i<r1)dfs(i+1,r1,l2+i-l1,r2-1);
   return;
  }
}
int main()
{
 scanf("%s",a);
 scanf("%s",b);
 len=strlen(a);
 dfs(0,len-1,0,len-1);
 return 0;
}