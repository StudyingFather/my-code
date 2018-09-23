#include <cstdio>
#include <algorithm>
using namespace std;
double minp=99999999;
int a,b,m,n;
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d",&a,&b);
  minp=min(minp,a*1.0/b);
 }
 printf("%.10lf",minp*m);
 return 0;
} 
