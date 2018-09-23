#include <stdio.h>
char s[105][105];
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=4;i++)
  for(int j=1;j<=n;j++)
   s[i][j]='.';
 if((k%2==0&&k<=2*n-4)||(k%(n-2)==0&&k<=2*n-4))
 {
  puts("YES");
  int t;
  if(k%2==0)
  {
   t=k/2;
   for(int i=2;i<=t+1;i++)//Êú×ÅÆÌ
    for(int j=2;j<=3;j++)
     s[j][i]='#';
  }
  else
  {
   t=k/(n-2);
   for(int i=2;i<=t+1;i++)//ºá×ÅÆÌ 
    for(int j=2;j<=n-1;j++)
     s[i][j]='#';
  }
  for(int i=1;i<=4;i++)
  {
   for(int j=1;j<=n;j++)
    printf("%c",s[i][j]);
   puts("");
  }
 }
 else puts("NO"); 
 return 0;
}
