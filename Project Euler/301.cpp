#include <stdio.h>
int main()
{
 int ans=0;
 for(long long i=1;i<=1073741824;i++)
 {
  int num=i^(2*i)^(3*i);
  if(num==0)ans++;
 }
 printf("%d",ans);
 return 0;
}
