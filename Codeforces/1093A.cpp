#include <stdio.h>
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int x;
  scanf("%d",&x);
  printf("%d\n",(x/7)+(x%7==0?0:1));
 }
 return 0;
}
