#include <stdio.h>
#include <algorithm>
using namespace std;
struct node
{
 int a,b;
}l[10005];
bool cmp(const node&a,const node&b)
{
 return a.b<b.b;
}
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&l[i].a,&l[i].b);
 sort(l+1,l+n+1,cmp);
 int x=l[1].b-1,y=l[1].b,ans=2;
 for(int i=2;i<=n;i++)
 {
  if(x>=l[i].a&&y<=l[i].b)continue;
  if(x<l[i].a&&y>=l[i].a)
  {
   x=y;
   y=l[i].b;
   ans++;
  }
  if(l[i].a>y)
  {
   x=l[i].b-1;
   y=l[i].b;
   ans+=2;
  }
 }
 printf("%d\n",ans);
 return 0;
}
