#include <stdio.h>
#include <string.h>
int n,len;
char a[100];
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%s",a);
  len=strlen(a);
  if(a[len-1]%2)printf("odd\n");
  else printf("even\n");
 }
 return 0;
}
