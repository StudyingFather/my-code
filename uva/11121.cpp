#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[35],cnt;
int main()
{
 int n,kase=0;
 scanf("%d",&n);
 while(n--)
 {
  int num;
  scanf("%d",&num);
  memset(a,0,sizeof(a));
  cnt=0;
  printf("Case #%d: ",++kase);
  if(num==0)puts("0");
  else
  {
   while(num!=0)
   {
    a[++cnt]=abs(num%2);
    if(num>=0)num/=-2;
    else num=(num-1)/(-2);
   }
   for(int i=cnt;i>=1;i--)
    printf("%d",a[i]);
   puts("");
  }
 }
 return 0;
}
