#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2147483647
char a[305],b[305];
int main()
{
 char f;
 while(scanf("%s %c %s",a,&f,b)==3) 
 {
  printf("%s %c %s\n",a,f,b);
  double a1=atof(a);
  double b1=atof(b);
  if(a1>MAX)printf("first number too big\n");
  if(b1>MAX)printf("second number too big\n");
  if (f=='+')
  {
   if((a1+b1)>MAX)printf("result too big\n");
  } 
  else if (f=='*') 
  {
   if((a1*b1)>MAX)printf("result too big\n");
  }
 }
 return 0;
}
