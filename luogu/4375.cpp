#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
 int num,id;
}a[100005];
int n,ans=1,vis[100005];
bool cmp(const node&a,const node&b)
{
 return a.num<b.num||(a.num==b.num&&a.id<b.id);
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i].num);
  a[i].id=i;
 }
 sort(a+1,a+n+1,cmp);
 int cnt=0;
 for(int i=1;i<=n;i++)
 {
  if(a[i].id>i)cnt++;
  if(vis[i])cnt--;
  vis[a[i].id]=1;
  ans=max(ans,cnt);
 }
 printf("%d\n",ans);
 return 0;
}
