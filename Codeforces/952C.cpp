#include <cstdio>
#include <algorithm>
using namespace std;
int a[15];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  if(abs(a[i]-a[i-1])>=2&&i!=1)
  {
   printf("NO");
   return 0;
  }
 }
 sort(a+1,a+n+1);
 for(int i=1;i<n;i++)
  if(a[i+1]-a[i]>=2)
  {
   printf("NO");
   return 0;
  }
 printf("YES");
 return 0;
}
