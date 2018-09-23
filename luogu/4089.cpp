#include <stdio.h>
#include <string.h>
int a[100005],b[100005],c[100005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  a[i]=1;
 for(int i=1;i<=n;i++)
  scanf("%d",&c[i]);
 for(int i=1;i<=500;i++)
 {
  for(int i=1;i<=n;i++)
   b[c[i]]+=a[i];
  memset(a,0,sizeof(a));
  for(int i=1;i<=n;i++)
   a[c[i]]+=b[i];
  memset(b,0,sizeof(b));
 }
 int ans=0;
 for(int i=1;i<=n;i++)
  if(a[i])ans++;
 printf("%d",ans);
 return 0;
}
