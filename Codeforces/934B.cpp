#include <stdio.h>
using namespace std;
const int loop[]={1,0,0,0,1,0,1,0,2,1};
int main()
{
 int k;
 scanf("%d",&k);
 if(k>36)printf("-1");
 else if(k<=18)
 {
  for(int i=1;i<=k;i++)
   printf("9");
 }
 else
 {
  for(;k>=2;k-=2)
   printf("8");
  if(k)printf("9");
 }
 return 0;
}
