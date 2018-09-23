#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int t,v;
}a[100];
int n,tong[205];
int cmp(const node&a,const node&b)
{
 return (a.v>b.v)||(a.v==b.v&&a.t<b.t);
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i].t);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i].v);
 sort(a+1,a+n+1,cmp);
 int ans=0;
 for(int i=1;i<=n;i++)
  for(int j=a[i].t;j>=1;j--)
   if(!tong[j])
   {
   	ans+=a[i].v;
   	tong[j]=!tong[j];
   	break;
   }
 printf("%d",ans);
 return 0;
}
