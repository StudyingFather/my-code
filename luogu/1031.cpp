#include <stdio.h>
int a[105],ave,n,ans;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  ave+=a[i];
 }
 ave/=n;
 for(int i=1;i<n;i++)
 {
  if(a[i]==ave)continue;
  int m=a[i]-ave;
  a[i+1]+=m;
  a[i]-=m;
  ans++;
 }
 printf("%d",ans);
 return 0;
}
