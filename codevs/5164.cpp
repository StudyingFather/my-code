#include <stdio.h>
#include <stdlib.h>
double calc() 
{
 char a[10];
 scanf("%s", a);
 switch(a[0])
 {
  case '+':
  return calc()+calc();
  case '-':
  return calc()-calc();
  case '*':
  return calc()*calc();
  case '/':
  return calc()/calc();
  default:
  return atof(a);
 }
}
int main()
{
 double ans;
 ans=calc();
 printf("%lf\n",ans);
 return 0;
}
