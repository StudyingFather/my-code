#include <stdio.h>
int n,m,p,a[100005],num,ans;
int main()
{
 scanf("%d%d%d",&n,&m,&p);
 for(int i=1;i<=m;i++)
 {
  scanf("%d",&num);
  a[num]++;
 }
 for(int i=1;i<=p;i++)
 {
  scanf("%d",&num);
  a[num]++;
 }
 for(int i=1;i<=n;i++)
  if(!a[i])ans++;
 printf("%d",ans);
 return 0;
}
