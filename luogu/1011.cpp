#include <stdio.h>
#include <string.h>
int a,n,m,x,bus[25],on[25],off[25];
int main()
{
 scanf("%d%d%d%d",&a,&n,&m,&x);
 for(int i=0;;i++)
 {
  memset(on,0,sizeof(on));
  memset(off,0,sizeof(off));
  memset(bus,0,sizeof(bus));
  on[1]=a;
  bus[1]=bus[2]=a;
  on[2]=i;
  off[2]=i;
  for(int j=3;j<=n-1;j++)
  {
   on[j]=on[j-1]+on[j-2];
   off[j]=on[j-1];
   bus[j]=bus[j-1]+on[j]-off[j];
  }
  if(bus[n-1]==m)
  {
   printf("%d",bus[x]);
   return 0;
  }
 }
}
