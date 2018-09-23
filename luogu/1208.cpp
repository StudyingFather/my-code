#include <cstdio>
#include <algorithm>
using namespace std;
struct milk
{
 int p,a;
}a[5005];
int cmp(const milk&a,const milk&b)
{
 return a.p<b.p;
}
int main()
{
 int n,m,ans=0;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
  scanf("%d%d",&a[i].p,&a[i].a);
 sort(a+1,a+m+1,cmp);
 for(int i=1;;i++)
 {
  ans+=min(n,a[i].a)*a[i].p;
  n-=a[i].a;
  if(n<=0)break;
 }
 printf("%d",ans);
 return 0;
}
