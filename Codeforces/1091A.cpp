#include <stdio.h>
int main()
{
 int a,b,c;
 scanf("%d%d%d",&a,&b,&c);
 for(int i=2;;i++)
  if(a<i-1||b<i||c<i+1)
  {
   printf("%d\n",3*(i-1));
   return 0;
  }
}
