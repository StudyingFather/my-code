#include <stdio.h>
#include <math.h>
const double gammanum=0.5772156649;
int main()
{
 int n;
 double ans=0;
 scanf("%d",&n);
 if(n==1)puts("0.00000");
 else if(n>1000000)printf("%.5lf\n",log(n)+gammanum+1);
 else
 {
  for(int i=1;i<n;i++)
   ans+=1.0/i;
  printf("%.5lf\n",ans+1);
 }
 return 0;
}
