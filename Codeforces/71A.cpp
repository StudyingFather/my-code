#include <stdio.h>
#include <string.h>
char a[105];
int main()
{
 int n;
 scanf("%d",&n);
 while(n--)
 {
  int len;
  scanf("%s",a);
  len=strlen(a);
  if(len<=10)puts(a);
  else printf("%c%d%c\n",a[0],len-2,a[len-1]);
 }
 return 0;
}
