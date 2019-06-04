#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005];
int main()
{
 int n,cnt1=0,cnt2=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  if(a[i]%2)cnt1++;
  else cnt2++;
 }
 if(cnt1==n||cnt2==n)
  for(int i=1;i<=n;i++)
   printf("%d ",a[i]);
 else
 {
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++)
   printf("%d ",a[i]);
 }
 return 0;
}