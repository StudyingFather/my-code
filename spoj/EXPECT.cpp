#include <stdio.h>
int main()
{
 int n;
 while(scanf("%d",&n)==1)
 {
  printf("%d\n",n);
  fflush(stdout);
  if(n==42)return 0;
 }
}
