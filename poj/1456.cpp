#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct goods
{
 int p,d;
}a[10005];
int cmp(const goods&a,const goods&b)
{
 return a.p>b.p;
}
int vis[10005];
int main()
{
 int n;
 while(~scanf("%d",&n))
 {
  memset(a,0,sizeof(a));
  memset(vis,0,sizeof(vis));
  int ans=0;
  for(int i=1;i<=n;i++)
  scanf("%d%d",&a[i].p,&a[i].d);
  sort(a+1,a+n+1,cmp);
  for(int i=1;i<=n;i++)
   for(int j=a[i].d;j;j--)
    if(!vis[j])
    {
     ans+=a[i].p;
     vis[j]=1;
     break;
    }
  printf("%d\n",ans);
 }
 return 0;
}
