#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
 int w,h,k,ans=0;
 scanf("%d%d%d",&w,&h,&k);
 for(int i=1;i<=k;i++)
 {
  ans+=(w+h)*2-4;
  w-=4,h-=4;
 }
 printf("%d\n",ans);
 return 0;
}
