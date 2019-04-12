#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int tag[100005],ans[100005],id[100005],a[100005];
int n,m,l;
void update(int x,int y)
{
 for(int i=x;i<=min(id[x]*l,y);i++)
 {
  ans[id[x]]-=a[i]^tag[id[x]];
  a[i]^=1;
  ans[id[x]]+=a[i]^tag[id[x]];
 }
 if(id[x]!=id[y])
  for(int i=(id[y]-1)*l+1;i<=y;i++)
  {
   ans[id[y]]-=a[i]^tag[id[y]];
   a[i]^=1;
   ans[id[y]]+=a[i]^tag[id[y]];
  }
 for(int i=id[x]+1;i<=id[y]-1;i++)
  tag[i]^=1,ans[i]=l-ans[i];
}
int query(int x,int y)
{
 int res=0;
 for(int i=x;i<=min(id[x]*l,y);i++)
  res+=a[i]^tag[id[x]];
 if(id[x]!=id[y])
  for(int i=(id[y]-1)*l+1;i<=y;i++)
   res+=a[i]^tag[id[y]];
 for(int i=id[x]+1;i<=id[y]-1;i++)
  res+=ans[i];
 return res;
}
int main()
{
 scanf("%d%d",&n,&m);
 l=sqrt(n);
 for(int i=1;i<=n;i++)
  id[i]=(i-1)/l+1;
 for(int i=1;i<=m;i++)
 {
  int c,a,b;
  scanf("%d%d%d",&c,&a,&b);
  if(!c)update(a,b);
  else printf("%d\n",query(a,b));
 }
 return 0;
}