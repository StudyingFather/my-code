#include <cstdio>
#include <algorithm>
using namespace std;
int a[10005],f[10005];
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
 {
  int maxa=a[i];
  for(int j=i;j>0&&j>i-k;j--)
  {
   maxa=max(a[j],maxa);
   f[i]=max(f[i],f[j-1]+(i-j+1)*maxa);
  }
 }
 printf("%d\n",f[n]);
 return 0;
}