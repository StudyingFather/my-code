#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int t,id;
}a[1005];
int cmp(const node&a,const node&b)
{
 return a.t<b.t;
}
int n;
double ave;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i].t);
  a[i].id=i;
 }
 sort(a+1,a+n+1,cmp);
 for(int i=1;i<=n;i++)
 {
  printf("%d ",a[i].id);
  ave+=a[i].t*(n-i);
 }
 puts("");
 ave/=n;
 printf("%.2lf",ave);
 return 0;
}
