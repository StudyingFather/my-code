#include <stdio.h>
int f[255],sum;
int main()
{
 f[1]=1;
 f[2]=2;
 sum+=2;
 for(int i=3;;i++)
 {
  f[i]=f[i-1]+f[i-2];
  if(f[i]>4000000)break;
  if(f[i]%2==0)sum+=f[i];
 }
 printf("%d",sum);
 return 0;
}
