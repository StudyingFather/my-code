#include <stdio.h>
#include <string.h>
char a[15],b[15];
int a1=1,b1=1;
int main()
{
 scanf("%s",a);
 scanf("%s",b);
 for(int i=0;i<strlen(a);i++)
  a1=a1*(a[i]-64)%47;
 for(int i=0;i<strlen(b);i++)
  b1=b1*(b[i]-64)%47;
 printf("%s",a1==b1?"GO":"STAY");
 return 0;
}
