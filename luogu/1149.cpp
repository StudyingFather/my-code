#include <stdio.h>
int a[2000]={6,2,5,5,4,5,6,3,7,6};
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 n-=4;
 for(int i=10;i<=2000;i++)
  a[i]=a[i/10]+a[i%10];
 for(int i=0;i<=1000;i++)
  for(int j=0;j<=1000;j++)
   if(a[i]+a[j]+a[i+j]==n)ans++;
 printf("%d",ans);
 return 0;
}
