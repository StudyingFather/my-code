#include <cstdio>
#include <algorithm>
using namespace std;
struct huashen
{
 int x,y,a;
}a[405];
int cmp(const huashen&a,const huashen&b)
{
 return a.a>b.a;
}
int main()
{
 int m,n,k,have_huashen=0,t,ans=0;
 scanf("%d%d%d",&m,&n,&k);
 for(int i=1;i<=m;i++)
  for(int j=1;j<=n;j++)
  {
   int num;
   scanf("%d",&num);
   if(num)
   {
    have_huashen++;
    a[have_huashen].x=j;
    a[have_huashen].y=i;
    a[have_huashen].a=num;
   }
  }
 sort(a+1,a+have_huashen+1,cmp);
 for(int i=1;i<=have_huashen;i++)
 {
  t=a[1].y+a[i].y;
  for(int j=2;j<=i;j++)
   t+=abs(a[j].x-a[j-1].x)+abs(a[j].y-a[j-1].y);
  t+=i;
  if(t>k||(t<=k&&i==have_huashen))
  {
   if(t>k)i--;
   for(int h=1;h<=i;h++)
    ans+=a[h].a;
   printf("%d",ans);
   return 0;
  }
 }
}
