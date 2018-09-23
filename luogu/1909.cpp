#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct pencil
{
 int shuliang,jiage;
}a[5];
int main()
{
 int n,ans=2147483647;
 scanf("%d",&n);
 for(int i=1;i<=3;i++)
 {
  scanf("%d%d",&a[i].shuliang,&a[i].jiage);
  ans=min(ans,(int)ceil(n*1.0/a[i].shuliang)*a[i].jiage);
 }
 printf("%d",ans);
 return 0;
}
