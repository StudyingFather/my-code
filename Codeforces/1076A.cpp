#include <stdio.h>
char s[200005];
int main()
{
 int n;
 scanf("%d",&n);
 scanf("%s",s);
 for(int i=0;i<n-1;i++)
  if(s[i]>s[i+1])
  {
   for(int j=0;j<n;j++)
    if(j!=i)putchar(s[j]);
   return 0;
  }
 for(int i=0;i<n-1;i++)
  putchar(s[i]);
 return 0;
}
