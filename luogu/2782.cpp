#include <cstdio>
#include <algorithm>
using namespace std;
struct city
{
 int a,b;
}c[250005];
int f[250005],ans;
bool cmp(const city&x,const city&y)
{
 return x.a<y.a;
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&c[i].a,&c[i].b);
 sort(c+1,c+n+1,cmp);
 for(int i=1;i<=n;i++)
  if(c[i].b>=f[ans]) f[++ans]=c[i].b;
  else f[lower_bound(f,f+ans,c[i].b)-f]=c[i].b;
 printf("%d",ans);
 return 0;
}
