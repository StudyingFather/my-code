#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define maxn 5005
using namespace std;
int n,f[5005],a[5005],ans,c[5005];
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  scanf("%d",&c[i]);
 int ansc=1000000000;
 for(int i=2;i<=n-1;i++)
 {
  int lmin=1000000000,rmin=1000000000;
  for(int j=i-1;j>=1;j--)
   if(a[j]<a[i])lmin=min(lmin,c[j]);
  for(int j=i+1;j<=n;j++)
   if(a[j]>a[i])rmin=min(rmin,c[j]);
  ansc=min(ansc,c[i]+lmin+rmin);
 }
 if(ansc!=1000000000)printf("%d",ansc);
 else printf("-1");
 return 0;
}
