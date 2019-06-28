#include <cstdio>
#include <algorithm>
using namespace std;
int a[5];
int main()
{
 int t;
 scanf("%d",&t);
 for(int kase=1;kase<=t;kase++)
 {
  scanf("%d%d%d",&a[0],&a[1],&a[2]);
  sort(a,a+3);
  printf("Case %d: %d\n",kase,a[1]);
 }
 return 0;
}
