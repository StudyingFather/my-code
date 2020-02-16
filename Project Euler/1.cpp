#include <stdio.h>
int t[1005],sum;
int main()
{
 for(int i=1;i*3<1000;i++)
  t[i*3]=1;
 for(int i=1;i*5<1000;i++)
  t[i*5]=1;
 for(int i=1;i<1000;i++)
  if(t[i]==1)sum+=i;
 printf("%d",sum);
 return 0;
}
