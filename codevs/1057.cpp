#include <stdio.h>
int main()
{
 int a,n=0,b=0,flag=1,yf;
 for(int i=1;i<=12;i++)
 {
  int x=0;
  b+=300;
  scanf("%d",&a);
  b-=a;
  x=b/100;
  b-=x*100;
  n+=x*100;
  if(b<0)
  {
   yf=i;
   flag=0;
   break;
  }
 }
 if(flag)
 {
  double bank=1.2*n+b;
  printf("%.0lf",bank);
 }
 else printf("%d",-yf);
 return 0;
}
