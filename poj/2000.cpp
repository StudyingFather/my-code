#include <stdio.h>
int calc(int day)
{
 int total=0;
 for(int i=1;;i++)
  for(int j=1;j<=i;j++)
  {
   total+=i;
   day--;
   if(!day)return total;
  }
}
int main()
{
 int day;
 scanf("%d",&day);
 printf("%d",calc(day));
 return 0;
}
