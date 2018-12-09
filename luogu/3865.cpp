#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int f[100005][25];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d",&f[i][0]);
 for(int i=1;(1<<i)<=n;i++)
  for(int j=1;j+(1<<i)<=n+1;j++)
   f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
 for(int i=1;i<=m;i++)
 {
  int l,r;
  scanf("%d%d",&l,&r);
  int k=log2(r-l+1);
  printf("%d\n",max(f[l][k],f[r-(1<<k)+1][k]));
 }
 return 0;
}
