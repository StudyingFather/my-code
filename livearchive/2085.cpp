#include <stdio.h>
#include <string.h>
int num;
char a[1005];
int main()
{
 while(scanf("%s",a)&&a[0]!='0')
 {
  num=0;
  int len=strlen(a);
  for(int i=0;i<len;i++)
   num+=a[i]-48;
  while(num>=10)
  {
   int n=num;
   num=0;
   while(n)
   {
    num+=n%10;
    n/=10;
   }
  }
  printf("%d\n",num);
 }
 return 0; 
}
