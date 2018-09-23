#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void divide(int n)
{
 if(n==1)printf("2(0)");
 else if(n==2) printf("2");
 else
 {
  int i,sum=1,ok,tem=n;
  for(i=1;;i++)
  {
   sum=sum*2;
   if(sum==n){ n=i;ok=1;break;}
   if(sum>n){n=i-1;ok=2;break;}
  }
  if(n==1) printf("2");
  else if(ok==1)
  {
   printf("2(");
   divide(n);
   printf(")");
  }
  else if(ok==2)
  {
   printf("2(");
   divide(n);
   printf(")");
  }
  if(n==1||ok==2)
  { 
   printf("+");
   divide(tem-(int)pow((double)2,(double)n));
  }
 }
}
int main()
{
 int n;
 scanf("%d",&n);
 divide(n);
 return 0;
}
