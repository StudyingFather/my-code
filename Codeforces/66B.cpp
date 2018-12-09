#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[1005],ans; 
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
 {
  int l=i,r=i,ln=a[i],rn=a[i];
  while(l>1&&a[l-1]<=ln)
   ln=a[--l];
  while(r<n&&a[r+1]<=rn)
   rn=a[++r];
  ans=max(ans,r-l+1);
 }
 printf("%d\n",ans);
 return 0;
}
