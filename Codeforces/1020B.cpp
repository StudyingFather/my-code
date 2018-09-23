#include <stdio.h>
#include <string.h>
int a[1005],t[1005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
 {
  memset(t,0,sizeof(t));
  int cur=i;
  while(t[cur]<2)
  {
   t[cur]++;
   if(t[cur]>=2)break;
   cur=a[cur];
  }
  printf("%d ",cur);
 }
 return 0;
}
