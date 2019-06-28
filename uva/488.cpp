#include <stdio.h>
int n,f,kz;
int main()
{
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
  scanf("%d",&f);
  scanf("%d",&kz);
  for(int j=0;j<kz;j++)
  {
   for(int x=1;x<f;x++)  
   {
    for(int y=1;y<=x;y++)
     printf("%d",x);
    printf("\n");
   }
   for(int x=f;x>=1;x--)  
   {
    for(int y=x;y>=1;y--)
     printf("%d",x);
    printf("\n");
   }
   if(i<=n-1)
   {
    if(j<kz-1)printf("\n");
    else if(i<n-1)printf("\n");
   }
  }
 }  
 return 0;
}
