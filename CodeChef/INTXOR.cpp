#include <stdio.h>
int a[50005];
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
   printf("1 %d %d %d\n",i,i,i);
   fflush(stdout);
   scanf("%d",&a[i]);
  }
  puts("2");
  fflush(stdout);
  for(int i=1;i<=n;i++)
   printf("%d ",a[i]);
  puts("");
  fflush(stdout);
  int op;
  scanf("%d",&op);
 }
 return 0;
}
