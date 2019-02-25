#include <cstdio>
#include <algorithm>
using namespace std;
struct mountain
{
 int x,y,l,r;
}a[100005];
bool cmp(const mountain&a,const mountain&b)
{
 return a.l<b.l||(a.l==b.l&&a.y>b.y);
}
int main()
{
 int n,pl=0,pr=0;
 scanf("%d",&n);
 int ans=n;
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d",&a[i].x,&a[i].y);
  a[i].l=a[i].x-a[i].y,a[i].r=a[i].x+a[i].y;
 }
 sort(a+1,a+n+1,cmp);
 for(int i=1;i<=n;i++)
 {
  if(a[i].l>=pl&&a[i].r<=pr)ans--;
  pl=min(pl,a[i].l),pr=max(pr,a[i].r);
 }
 printf("%d\n",ans);
 return 0;
}