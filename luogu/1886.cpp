#include <stdio.h>
int a[1000005],que[1000005],h,t,p[1000005];
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 h=0,t=1;
 for(int i=1;i<=n;i++)
 {
  while(h<t&&a[i]<=que[t-1])
   t--;
  p[t]=i;
  que[t++]=a[i];
  while(p[h]<=i-k)h++;
  if(i>=k)printf("%d ",que[h]);
 }
 puts("");
 h=0,t=1;
 for(int i=1;i<=n;i++)
 {
  while(h<t&&a[i]>=que[t-1])
   t--;
  p[t]=i;
  que[t++]=a[i];
  while(p[h]<=i-k)h++;
  if(i>=k)printf("%d ",que[h]);
 }
 puts("");
 return 0;
} 
