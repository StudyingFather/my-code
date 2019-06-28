#include <stdio.h>
int main()
{
 for(int i=3;;i++)
  for(int j=i+1;i+j<=1000;j++)
   if(i*i+j*j==(1000-i-j)*(1000-i-j))
   {
    printf("%d",i*j*(1000-i-j));
    return 0;
   }
}
