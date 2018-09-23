#include <stdio.h>
int t[1005],n,a[55],ans[55],cnt;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=n;i>=1;i--)
 {
  t[a[i]]++;
  if(t[a[i]]==1)ans[++cnt]=a[i];
 }
 printf("%d\n",cnt);
 for(int i=cnt;i>=1;i--)
  printf("%d ",ans[i]);
 return 0;
}
