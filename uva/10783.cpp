#include <stdio.h>
int t,a,b,sum;
int main()
{
 scanf("%d",&t);
 for(int i=1;i<=t;i++)
 {
  sum=0;
  scanf("%d%d",&a,&b);
  if(a%2==0)a++;
  for(int j=a;j<=b;j+=2)
   sum+=j;
  printf("Case %d: %d\n",i,sum);
 }
 return 0;
}
