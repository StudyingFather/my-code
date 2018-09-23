#include <cstdio>
#include <algorithm>
using namespace std;
int a[200005];
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 sort(a+1,a+n+1);
 if(k==0)
 {
  if(a[1]!=1)printf("%d",a[1]-1);
  else printf("-1");
 }
 else if(k==n)printf("%d",a[n]);
 else if(a[k]==a[k+1])printf("-1");
 else printf("%d",a[k]);
 return 0;
}
