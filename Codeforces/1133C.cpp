#include <cstdio>
#include <algorithm>
using namespace std;
int a[200005];
int main()
{
 int n,ans=1;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 sort(a+1,a+n+1);
 int l=1,r=1;
 while(l<=n)
 {
  while(a[r+1]-a[l]<=5&&r<n)
  {
   r++;
   ans=max(ans,r-l+1);
  }
  l++;
 }
 printf("%d\n",ans);
 return 0;
}