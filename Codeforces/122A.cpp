#include <stdio.h>
int n;
int main()
{
 scanf("%d",&n);
 if(n%4==0||n%7==0||n%47==0)
 {
  printf("YES");
  return 0;
 }
 else
 {
  while(n)
  {
   int m=n%10;
   if(m!=4&&m!=7)
   {
    printf("NO");
    return 0;
   }
   n/=10;
  }
 }
 printf("YES");
 return 0;
}
