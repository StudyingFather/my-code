#include <cstdio>
#include <algorithm>
using namespace std;
int r[1005];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int add;
  scanf("%d",&add);
  r[add]++;
 }
 sort(r+1,r+n+1);
 printf("%d",r[1]);
 return 0;
}
