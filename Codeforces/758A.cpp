#include <stdio.h>
int main()
{
 int maxa=0,n,a,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a);
  if(a>maxa)maxa=a;
  ans+=a;
 }
 printf("%d",maxa*n-ans);
 return 0;
}
