#include <stdio.h>
char s[205];
int cur;
int main()
{
 int a,b,x;
 scanf("%d%d%d",&a,&b,&x);
 if(a>b)
 {
  s[0]='0';
  a--;
 }
 else
 {
  s[0]='1';
  b--;
 }
 while(a+b)
 {
  if(a+b==1)
  {
   if(a)s[++cur]='0';
   else s[++cur]='1';
   break;
  }
  if(x==1)
  {
   if(s[cur]=='1'&&b==0)
   {
   	a--;
   	s[++cur]='0';
   	x--;
   }
   else if(s[cur]=='0'&&a==0)
   {
   	b--;
   	s[++cur]='1';
   	x--;
   }
  }
  if(x>1)
  {
   if(s[cur]=='1')
   {
   	a--;
   	s[++cur]='0';
   }
   else
   {
   	b--;
   	s[++cur]='1';
   }
   x--;
  }
  else
  {
   if(s[cur]=='0')
   {
   	s[++cur]='0';
   	a--;
   }
   else
   {
   	s[++cur]='1';
   	b--;
   }
  }
 }
 printf("%s",s);
 return 0;
}
