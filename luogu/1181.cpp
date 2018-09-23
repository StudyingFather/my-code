#include <stdio.h>
int a[100005],n,m,sum,ans;
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  if(sum+a[i]>m)
  {
   ans++;
   sum=a[i];
  }
  else sum+=a[i];
 }
 printf("%d",sum==0?ans:ans+1);
 return 0;
} 
