#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int l,r;
}a[155];
bool cmp(const node&a,const node&b)
{
 return a.r<b.r||(a.r==b.r&&a.l<b.l);
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&a[i].l,&a[i].r);
 sort(a+1,a+n+1,cmp);
 int cur1=0,cur2=0,ans=0;
 for(int i=1;i<=n;i++)
  if(cur1<=a[i].l)
  {
   ans++;
   cur1=a[i].r;
  }
  else if(cur2<=a[i].l)
  {
   ans++;
   cur2=a[i].r;
   swap(cur1,cur2);
  }
 printf("%d\n",ans);
 return 0;
}
