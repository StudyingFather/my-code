#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int L,v,l,r;
  scanf("%d%d%d%d",&L,&v,&l,&r);
  printf("%d\n",L/v-r/v+(l-1)/v);
 }
 return 0;
}
