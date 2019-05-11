#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 if(m==0)puts("1");
 else printf("%d\n",min(m,n-m));
 return 0;
}