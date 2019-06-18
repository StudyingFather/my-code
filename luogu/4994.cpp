#include <stdio.h>
int f[2];
int main()
{
 int m;
 scanf("%d",&m);
 f[0]=0,f[1]=1;
 for(int i=2;;i++)
 {
  f[i%2]=(f[0]+f[1])%m;
  if((f[0]==0||f[1]==0)&&(f[0]+f[1])%m==1)
  {
   printf("%d\n",i);
   return 0;
  }
 }
}