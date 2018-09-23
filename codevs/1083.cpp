#include <stdio.h>
int main()
{
 int n;
 scanf("%d",&n);
 int k=1,s=0;
 for(;;)
 {
  s+=k;
  if(s>=n)
  {
   if(k-s+n==1)printf("%d/%d",k-s+n,s-n+1);
   else printf("%d/%d",s-n+1,k-s+n);
   return 0;
  }
  k++;
 }
}
