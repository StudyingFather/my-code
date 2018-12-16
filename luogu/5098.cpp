#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int px[50005],py[50005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  px[i]=x+y;
  py[i]=x-y;
 }
 sort(px+1,px+n+1);
 sort(py+1,py+n+1);
 printf("%d\n",max(px[n]-px[1],py[n]-py[1]));
 return 0;
}
