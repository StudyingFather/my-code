#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
 int g,b;
 while(~scanf("%d%d",&g,&b)&&g!=-1&&b!=-1)
 {
  if(b>g)swap(b,g);
  printf("%d\n",(int)ceil(g*1.0/(b+1)));
 }
 return 0;
}
