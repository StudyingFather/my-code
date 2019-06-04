#include <cstdio>
#include <algorithm>
using namespace std;
int a[2005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=2*n;i++)
  scanf("%d",&a[i]);
 sort(a+1,a+2*n+1);
 if(a[1]==a[2*n])
 {
  puts("-1");
  return 0;
 }
 else
  for(int i=1;i<=2*n;i++)
   printf("%d ",a[i]);
 return 0;
}