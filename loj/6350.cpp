#include <stdio.h>
int main()
{
 int x,k;
 scanf("%d%d",&x,&k);
 for(int i=1;i<k;i++)
  printf("%d 0\n",i);
 printf("%d 1\n",x-k+1);
 return 0;
}