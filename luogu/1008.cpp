#include <stdio.h>
#include <string.h>
int vis[15];
void cha(int a)
{
 for(int i=1;i<=3;i++)
 {
  vis[a%10]++;
  a/=10;
 }
}
int main()
{
 for(int a=100;a<=333;a++)
 {
  memset(vis,0,sizeof(vis));
  int b=2*a;
  int c=3*a;
  cha(a);
  cha(b);
  cha(c);
  int flag=1;
  for(int i=1;i<=9;i++)
   if(vis[i]!=1)
   {
   	flag=0;
   	break;
   }
  if(flag==1)printf("%d %d %d\n",a,b,c);
 }
 return 0;
}
