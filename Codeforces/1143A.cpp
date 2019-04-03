#include <cstdio>
#include <algorithm>
using namespace std;
int a[200005],cnt0,cnt1;
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  if(a[i])cnt1++;
  else cnt0++;
 }
 for(int i=1;i<=n;i++)
 {
  if(a[i])cnt1--;
  else cnt0--;
  if(!cnt0||!cnt1)
  {
   printf("%d\n",i);
   return 0;
  }
 }
}