#include <cstdio>
int main()
{
 int a,b;
 scanf("%d%d",&a,&b);
 if(a<=0&&b>=0)puts("Zero");
 else if(b<0)
 {
  if((a-b+1)%2)puts("Negative");
  else puts("Positive");
 }
 else puts("Positive");
 return 0;
}