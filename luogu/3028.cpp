#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int x,y;
}a[100005];
bool cmp(const node&a,const node&b)
{
 return a.x<b.x||(a.x==b.x&&a.y>b.y);
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int l,r;
  scanf("%d%d",&l,&r);
  a[i].x=l,a[i].y=1;
  a[i+n].x=r,a[i+n].y=-1;
 }
 sort(a+1,a+2*n+1,cmp);
 int ans=0,cur=0;
 for(int i=1;i<=2*n;i++)
 {
  cur+=a[i].y;
  ans=max(ans,cur);
 }
 printf("%d\n",ans);
 return 0;
}
