#include <cstdio>
#include <algorithm>
using namespace std;
struct segment
{
 int l,r,id;
}a[300005];
int cmp(const segment&a,const segment&b)
{
 return a.l<b.l||(a.l==b.l&&a.r>b.r);
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d",&a[i].l,&a[i].r);
  a[i].id=i;
 }
 sort(a+1,a+n+1,cmp);
 for(int i=2;i<=n;i++)
  if(a[i].r<=a[1].r)
  {
   printf("%d %d",a[i].id,a[1].id);
   return 0;
  }
 printf("-1 -1");
 return 0;
}
