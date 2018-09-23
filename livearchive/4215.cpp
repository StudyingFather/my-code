#include <stdio.h>
int re[105];
int main()
{
 int n;
 for(int i=1;i<=100;i++)
  re[i]=re[i-1]+i*i;
 while(~scanf("%d",&n)&&n)
  printf("%d\n",re[n]);
 return 0;
}
