#include <cstdio>
#include <algorithm>
using namespace std;
int fa[200005],a[200005];
int gcd(int x,int y)
{
 return y==0?x:gcd(y,x%y);
}
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<n;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  fa[v]=u;
 }
 for(int i=1;i<=k;i++)
 {
  int op;
  scanf("%d",&op);
  if(op==1)
  {
   int x,flag=0;
   scanf("%d",&x);
   for(int i=fa[x];i;i=fa[i])
    if(gcd(a[i],a[x])!=1)
    {
     printf("%d\n",i);
     flag=1;
     break;
    }
   if(!flag)puts("-1");
  }
  else
  {
   int x,y;
   scanf("%d%d",&x,&y);
   a[x]=y;
  }
 }
 return 0;
}