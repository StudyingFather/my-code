#include <cstdio>
int v[25],c[25];
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&v[i]);
 for(int i=1;i<=n;i++)
  scanf("%d",&c[i]);
 for(int i=1;i<=n;i++)
  if(v[i]>c[i])ans+=v[i]-c[i];
 printf("%d\n",ans);
 return 0;
}