#include <cstdio>
#include <algorithm>
using namespace std;
struct num
{
 int n,k;
}a[10005];
int b[200005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&b[i]);
 sort(b+1,b+n+1);
 int tmp=0;
 for(int i=1;i<=n;i++)
 {
  if(a[tmp].n==b[i])a[tmp].k++;
  else
  {
   tmp++;
   a[tmp].n=b[i];
   a[tmp].k=1;
  }
 }
 for(int i=1;i<=tmp;i++)
  printf("%d %d\n",a[i].n,a[i].k);
 return 0;
}
