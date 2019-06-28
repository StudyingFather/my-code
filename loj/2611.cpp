#include <stdio.h>
int a[100005];
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  if(a[i]-a[i-1]>0)ans+=a[i]-a[i-1];
 }
 printf("%d\n",ans);
 return 0;
}