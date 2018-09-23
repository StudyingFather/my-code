#include <cstdio>
#include <algorithm>
using namespace std;
int w[105],c[105],f[1005];
int main()
{
 int t,m;
 scanf("%d%d",&t,&m);
 for(int i=1;i<=m;i++)
  scanf("%d%d",&c[i],&w[i]);
 for(int i=1;i<=m;i++)
  for(int j=t;j>=c[i];j--)
   f[j]=max(f[j],f[j-c[i]]+w[i]);
 printf("%d",f[t]);
 return 0;
}
