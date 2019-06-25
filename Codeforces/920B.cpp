#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct stu
{
 int id,l,r;
}a[1005];
int t,w[1005];
int cmp(const stu&a,const stu&b)
{
 return a.l<b.l||(a.l==b.l&&a.id<b.id);
}
int main()
{
 scanf("%d",&t);
 while(t--)
 {
  int n,s=0;
  memset(a,0,sizeof(a));
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
   a[i].id=i;
   scanf("%d%d",&a[i].l,&a[i].r);
  }
  sort(a+1,a+n+1,cmp);
  int t=a[1].l;
  for(int i=1;i<=n;i++)
  {
   if(w[i])continue;
   if(t>a[i].r)
   {
    printf("0 ");
    s++;
    a[i].id=a[i].l=a[i].r=0;
   }
   else if(t>=a[i].l)
   {
    printf("%d ",t);
    t++;
    s++;
    a[i].id=a[i].l=a[i].r=0;
   }
   if(i==n)
   {
    i=s;
    sort(a+1,a+n+1,cmp);
    t=a[s+1].l;
   }
   if(s==n)break;
  }
  puts("");
 }
 return 0;
}
