#include <stdio.h>
#include <string.h>
char a[105],zt;
int lxn;
int main()
{
 scanf("%s",a);
 int l=strlen(a);
 zt=a[0];
 lxn=1;
 for(int i=1;i<l;i++)
  if(a[i]==zt)
  {
   lxn++;
   if(lxn>=7)
   {
   	printf("YES");
   	return 0;
   }
  }
  else
  {
   lxn=1;
   zt=a[i];
  }
 printf("NO");
 return 0;
}
