#include <cstdio>
#include <algorithm>
using namespace std;
int a[35],cnt;
int main()
{
 int n;
 scanf("%d",&n);
 if(n==0)printf("0");
 else
 {
  while(n!=0)
  {
   a[++cnt]=abs(n%2);
   if(n>=0)n/=-2;
   else n=(n-1)/(-2);
  }
  for(int i=cnt;i>=1;i--)
   printf("%d",a[i]);
 }
 return 0;
}
