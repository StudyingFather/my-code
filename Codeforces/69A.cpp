#include <stdio.h>
int n,a[105][105];
int main()
{
 scanf("%d",&n);
 for(int r=1;r<=n;r++)
  for(int c=1;c<=3;c++)
   scanf("%d",&a[r][c]);
 for(int c=1;c<=3;c++)
 {
  int sum=0;
  for(int r=1;r<=n;r++)
   sum+=a[r][c];
  if(sum!=0)
  {
   printf("NO");
   return 0;
  }
 }
 printf("YES");
 return 0;
}
