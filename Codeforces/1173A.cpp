#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
 int x,y,z;
 scanf("%d%d%d",&x,&y,&z);
 int res1=x-y+z,res2=x-y-z;
 if(res1<0)res1=-1;
 else if(res1>0)res1=1;
 if(res2<0)res2=-1;
 else if(res2>0)res2=1;
 if(res1!=res2)puts("?");
 else if(!res1)puts("0");
 else if(res1>0)puts("+");
 else puts("-");
 return 0;
}