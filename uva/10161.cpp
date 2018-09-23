#include <stdio.h>
#include <math.h>
int main()
{
 int n,m,x,y;
 while(~scanf("%d",&n))
 {
  if(n==0)break;
  m=(int)floor(sqrt((double)n-0.1));
  x=m+1;
  if(n-m*m<=m+1)y=n-m*m;
  else
  {
   y=m+1;
   x-=n-m*m-m-1;
  }
  if(m%2==0)printf("%d %d\n",x,y);
  else printf("%d %d\n",y,x); 
 }
 return 0;
}
