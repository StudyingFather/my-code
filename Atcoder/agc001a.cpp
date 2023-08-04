#include <cstdio>
#include <algorithm>
using namespace std;
int a[205];
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=2*n;i++)
  scanf("%d",&a[i]);
 sort(a+1,a+2*n+1);
 for(int i=1;i<=2*n;i+=2)
  ans+=a[i];
 printf("%d\n",ans);
 return 0;
}