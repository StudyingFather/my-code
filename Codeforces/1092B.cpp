#include <cstdio>
#include <algorithm>
using namespace std;
int a[105];
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 sort(a+1,a+n+1);
 for(int i=1;i<=n;i+=2)
  ans+=a[i+1]-a[i];
 printf("%d\n",ans);
 return 0;
}
