#include <stdio.h>
int f(int x)
{
 if(x&1)return (-x-1)/2;
 return x/2;
}
int main()
{
 int q;
 scanf("%d",&q);
 while(q--)
 {
  int l,r;
  scanf("%d%d",&l,&r);
  printf("%d\n",f(r)-f(l-1));
 }
 return 0;
}
