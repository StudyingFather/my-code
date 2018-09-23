#include <stdio.h>
int main()
{
 int n,ans;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int num;
  scanf("%d",&num);
  ans^=num;
 }
 printf("%d",ans);
 return 0;
}
