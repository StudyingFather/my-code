#include <stdio.h>
char s[300005];
int main()
{
 int n;
 scanf("%d",&n);
 scanf("%s",s+1);
 for(int i=1;i<=n;i++)
  if(s[i-1]>s[i])
  {
   puts("YES");
   printf("%d %d\n",i-1,i);
   return 0;
  }
 puts("NO");
 return 0;
}