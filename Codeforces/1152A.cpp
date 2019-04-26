#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
 int n,m,x;
 int a1=0,a2=0,b1=0,b2=0;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&x);
  if(x%2)a1++;
  else a2++;
 }
 for(int i=1;i<=m;i++)
 {
  scanf("%d",&x);
  if(x%2)b1++;
  else b2++;
 }
 printf("%d\n",min(a1,b2)+min(a2,b1));
 return 0;
}