#include <cstdio>
#include <algorithm>
#define MOD 998244353
using namespace std;
int fa[4000005];
void unionn(int x,int y)
{
 fa[y]=x;
}
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
 int n,m,ans=0;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  fa[i]=i;
 for(int i=1;i<=m;i++)
 {
  int op,u,v;
  scanf("%d%d%d",&op,&u,&v);
  if(!op)
  {
   int x=find(u),y=find(v);
   if(x!=y)unionn(x,y);
  }
  else ans=((ans<<1)+(find(u)==find(v)))%MOD;
 }
 printf("%d\n",ans);
 return 0;
}