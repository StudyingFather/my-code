#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
 double s,x,v=7,l=0;
 scanf("%lf%lf",&s,&x);
 while(l<s-x)l+=v,v*=0.98;
 if(v*0.98<=s+x-l)puts("y");
 else puts("n");
 return 0;
}
