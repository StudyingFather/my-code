#include <cstdio>
#include <algorithm>
using namespace std;
struct activity
{
 int l,r;
}a[100005];
int cmp(const activity&a,const activity&b)
{
 return a.r<b.r||(a.r==b.r&&a.l<b.l);
}
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n,ans=0;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
   scanf("%d%d",&a[i].l,&a[i].r);
  sort(a+1,a+n+1,cmp);
  int t=0;
  for(int i=1;i<=n;i++)
   if(t<=a[i].l)
   {
    ans++;
    t=a[i].r;
   }
  printf("%d\n",ans);
 }
 return 0;
}
