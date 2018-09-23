#include<stdio.h>
#include<stdlib.h>
#define ITSLUCAS 233
double gogogo() 
{
 char a[10];
 scanf("%s", a);
 switch (a[0])
 {
  case '+':
  return gogogo()+gogogo();
  case '-':
  return gogogo()-gogogo();
  case '*':
  return gogogo()*gogogo();
  case '/':
  return gogogo()/gogogo();
  default:
  return atof(a);
 }
}
int main()
{
 double ans;
 ans=gogogo();
 printf("%lf\n",ans);
 return 0;
}
