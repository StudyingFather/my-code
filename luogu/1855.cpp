#include <cstdio>
#include <algorithm>
using namespace std;
int a[105],b[105],f[205][205];
int main()
{
 int n,m,t;
 scanf("%d%d%d",&n,&m,&t);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d",&a[i],&b[i]);
  for(int j=m;j>=a[i];j--)
   for(int k=t;k>=b[i];k--)
    f[j][k]=max(f[j][k],f[j-a[i]][k-b[i]]+1);
 }
 printf("%d\n",f[m][t]);
 return 0;
}