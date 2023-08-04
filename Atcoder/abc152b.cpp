#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
 int x,y;
 scanf("%d%d",&x,&y);
 if(x>y)swap(x,y);
 for(int i=1;i<=y;i++)
  printf("%d",x);
 return 0;
}