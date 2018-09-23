#include <stdio.h>
#include <math.h>
int ans[50];
const char list[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
int main()
{
 int n,r;
 scanf("%d%d",&n,&r);
 int r1=-r;
 int l=0;
 printf("%d=",n);
 while(n)
 {
  l++;
  ans[l]=n%r>=0?n%r:r1+(n%r);
  n=(n-ans[l])/r;
 }
 for(;l;l--)
  printf("%c",list[ans[l]]);
 printf("(base%d)",r);
 return 0;
}
