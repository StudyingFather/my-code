#include <stdio.h>
int main()
{
 int t,c,k,w;
 scanf("%d",&t);
 while(t--)
 {
  scanf("%d%d%d",&c,&k,&w);
  printf("%s\n",c*w<=k?"yes":"no");
 }
 return 0;
}
