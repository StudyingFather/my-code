#include <stdio.h>
int main()
{
 float a,sum=0;
 for(int i=1;i<=12;i++)
 {
  scanf("%f",&a);
  sum+=a;
 }
 printf("$%.2lf\n",sum/12);//G++用.2lf会WA，这一点很怪异
 return 0;
}
