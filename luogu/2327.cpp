#include <stdio.h>
#include <string.h>
int a[10005],b[10005];
int main()
{
 int n,ans=2;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 b[1]=1;
 for(int i=2;i<=n+1;i++)
 {
  b[i]=a[i-1]-b[i-1]-b[i-2];
  if(b[i]!=0&&b[i]!=1)
  {
   ans--;
   break;
  }
  if(b[n+1]!=0)ans--;
 }
 memset(b,0,sizeof(b));
 for(int i=2;i<=n+1;i++)
 {
  b[i]=a[i-1]-b[i-1]-b[i-2];
  if(b[i]!=0&&b[i]!=1)
  {
   ans--;
   break;
  }
  if(b[n+1]!=0)ans--;
 }
 printf("%d\n",ans);
 return 0;
}
