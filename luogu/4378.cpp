#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int num,id;
}a[100005];
bool cmp(const node&a,const node&b)
{
 return a.num<b.num||(a.num==b.num&&a.id<b.id);
}
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i].num);
  a[i].id=i;
 }
 sort(a+1,a+n+1,cmp);
 for(int i=1;i<=n;i++)
  ans=max(ans,a[i].id-i);
 printf("%d\n",ans+1);
 return 0;
}
