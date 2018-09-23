#include <cstdio>
#include <algorithm>
using namespace std;
int w[3405],c[3405],f[13005];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  scanf("%d%d",&c[i],&w[i]);
 for(int i=1;i<=n;i++)
  for(int j=m;j>=c[i];j--)
   f[j]=max(f[j],f[j-c[i]]+w[i]);
 printf("%d",f[m]);
 return 0;
}
