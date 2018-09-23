#include <stdio.h>
#include <math.h>
#include <string.h>
int a[3005],b[3005];
int main()
{
 int i,n,c;
 while(~scanf("%d",&n))
 {
  int flag=0;
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  for(i=1;i<=n;i++)
   scanf("%d",&a[i]);
  for(i=1;i<n;i++)
  {
   c=fabs(a[i]-a[i+1]);
   if(c>n-1)
   {
    printf("Not jolly\n");
    flag=1;
    break;
   }
   else b[c]++;
  }
  if(flag==1)continue;
  for(i=1;i<n;i++)
   if(b[i]==0)break;
  if(i>n-1)printf("Jolly\n");
  else printf("Not jolly\n");
 }
 return 0;
}
