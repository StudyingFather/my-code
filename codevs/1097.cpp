#include <stdio.h>
int a[10005]; 
int main()
{
 int b=0,l,m; 
 scanf("%d %d",&l,&m);
 for(int i=0;i<=l;i++)
  a[i]=1;
 for(int i=0;i<m;i++)
 {
  int a1,a2;
  scanf("%d %d",&a1,&a2);
  for(int j=a1;j<=a2;j++)
   a[j]=0; 
 }
 for(int i=0;i<=l;i++)
  if(a[i])b++;
 printf("%d",b);
 return 0;
}
