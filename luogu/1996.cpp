#include <stdio.h>
int n,m,p[105],out;
int main()
{
 scanf("%d%d",&n,&m);
 int cnt=0;
 for(int i=1;out!=n;i++)
 {
  if(!p[i])cnt++;
  if(cnt==m)
  {
   p[i]=1;
   printf("%d ",i);
   out++;
   cnt=0;
  }
  if(i==n)i=0;
 }
 return 0;
} 
