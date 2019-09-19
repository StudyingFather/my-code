#include <cstdio>
#include <algorithm>
using namespace std;
int f[2][100005];
int main()
{
 int n,v;
 scanf("%d%d",&n,&v);
 for(int i=1;i<=n;i++)
 {
  int p,g;
  scanf("%d%d",&p,&g);
  for(int j=v;j>=p;j--)
   f[i&1][j]=f[!(i&1)][j-p];
  for(int j=1;j<=g;j++)
  {
   int c,w;
   scanf("%d%d",&c,&w);
   for(int k=v;k>=c+p;k--)
    f[i&1][k]=max(f[i&1][k],f[i&1][k-c]+w);
  }
  for(int j=v;j>=0;j--)
   f[i&1][j]=max(f[i&1][j],f[!(i&1)][j]);
 }
 printf("%d\n",f[n&1][v]);
 return 0;
}