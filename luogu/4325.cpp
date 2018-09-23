#include <stdio.h>
int a[45];
int main()
{
 for(int i=1;i<=10;i++)
 {
  int num;
  scanf("%d",&num);
  a[num%42]++;
 }
 int ans=0;
 for(int i=0;i<42;i++)
  if(a[i])ans++;
 printf("%d",ans);
 return 0;
}
