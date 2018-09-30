#include <stdio.h>
int f[105];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int a,b;
  scanf("%d%d",&a,&b);
  for(int j=a;j<=b;j++)
   f[j]++;
 }
 for(int i=1;i<=n;i++)
  if(f[i]!=1)
  {
   printf("%d %d\n",i,f[i]);
   return 0;
  }
 puts("OK");
 return 0;
}