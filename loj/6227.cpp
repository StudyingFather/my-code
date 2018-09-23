#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n,blo;
int v[50005],bl[50005],atag[50005];
void add(int a,int b,int c)
{
 for(int i=a;i<=min(bl[a]*blo,b);i++)
  v[i]+=c;
 if(bl[a]!=bl[b])
  for(int i=(bl[b]-1)*blo+1;i<=b;i++)
   v[i]+=c;
 for(int i=bl[a]+1;i<=bl[b]-1;i++)
  atag[i]+=c;
}
int main()
{
 scanf("%d",&n);
 blo=sqrt(n);
 for(int i=1;i<=n;i++)
  scanf("%d",&v[i]);
 for(int i=1;i<=n;i++)
  bl[i]=(i-1)/blo+1;
 for(int i=1;i<=n;i++)
 {
  int f,a,b,c;
  scanf("%d%d%d%d",&f,&a,&b,&c);
  if(f==0)add(a,b,c);
  if(f==1)printf("%d\n",v[b]+atag[bl[b]]);
 }
 return 0;
}
