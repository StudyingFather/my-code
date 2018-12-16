#include <cstdio>
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n,k;
  scanf("%d%d",&n,&k);
  if((n&k)==k)puts("1");
  else puts("0");
 }
 return 0;
}
