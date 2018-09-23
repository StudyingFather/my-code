#include <stdio.h>
#include <string.h>
int a[7],my[35],p[8];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=7;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
 {
  memset(my,0,sizeof(my));
  for(int j=1;j<=7;j++)
  {
   int num;
   scanf("%d",&num);
   my[num]++;
  }
  int same=0;
  for(int j=1;j<=7;j++)
   if(my[a[j]])same++;
  p[same]++;
 }
 for(int i=7;i;i--)
  printf("%d ",p[i]);
 return 0;
}
