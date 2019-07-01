#include <stdio.h>
#include <string.h>
#include <math.h>
void calc(int*a,int*b)
{
 int i,j;
 int c[MAX];
 memset(c,0,sizeof(c));
 for(i=0;i<500;i++)
  for(j=0;j<500;j++)
  {
   if(i+j<500)
   {
    c[i+j]+=a[i]*b[j];
    c[i+j+1]+=c[i+j]/10;
    c[i+j]=c[i+j]%10;
   }
  }
 memcpy(a,c,500*sizeof(int));
}
int a[505],ans[505];
int main()
{
 int n,i,x;
 scanf("%d",&n);
 a[0]=2;ans[0]=1;x=n;
 while(x>0)
 {
  if(x%2==1)calc(ans,a);
  x/=2;
  calc(a,a);
 }
 n=n*(log(2)/log(10))+1;
 printf("%d\n",n);
 ans[0]--;
 for(i=499;i>=0;i--)
 {
  if(i%50==49&&i!=499)printf("\n");
  printf("%d",ans[i]);
 }
 return 0;
}
