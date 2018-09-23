#include <stdio.h>
int line[1000005];
int main()
{
 int n,m,c;
 scanf("%d%d%d",&n,&m,&c);
 int num;
 while(~scanf("%d",&num))
 {
  int flag=0;
  for(int i=1;i<=n;i++)
  {
   if(!line[i])
   {
    printf("%d",i);
    line[i]=num;
    flag=1;
    break;
   }
   if(line[i+1]>line[i]&&line[i+1]>num)
   {
    printf("%d",i);
    line[i]=num;
    flag=1;
    break;
   }
  }
  if(!flag)
  {
   printf("%d",n);
   line[n]=num;
  }
  puts("");
  fflush(stdout);
 }
 return 0;
}
