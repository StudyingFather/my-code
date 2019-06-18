#include <stdio.h>
struct people
{
 int dir;
 char name[15];
}p[100005];
int main()
{
 int n,m,now_d=0;
 scanf("%d%d",&n,&m);
 for(int i=0;i<n;i++)
  scanf("%d%s",&p[i].dir,p[i].name);
 for(int i=1;i<=m;i++)
 {
  int a,s;
  scanf("%d%d",&a,&s);
  s=((a^p[now_d].dir)==1)?s:-s;
  now_d+=s;
  while(now_d<0)
   now_d+=n;
  now_d%=n;
 }
 printf("%s",p[now_d].name);
 return 0;
}
