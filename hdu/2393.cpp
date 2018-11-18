#include <cstdio>
#include <algorithm>
using namespace std;
int f[3];
int main()
{
 int n;
 scanf("%d",&n);
 for(int kase=1;kase<=n;kase++)
 {
  scanf("%d%d%d",&f[0],&f[1],&f[2]);
  sort(f,f+3);
  printf("Scenario #%d:\n",kase);
  if(f[0]*f[0]+f[1]*f[1]==f[2]*f[2])puts("yes");
  else puts("no");
  puts("");
 }
 return 0;
}
