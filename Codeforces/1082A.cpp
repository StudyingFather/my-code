#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int n,x,y,d,ans=1000000000;
  scanf("%d%d%d%d",&n,&x,&y,&d);
  if(abs(y-x)%d==0)ans=min(ans,abs(y-x)/d);
  if((y-1)%d==0)ans=min(ans,int(ceil((double)(x-1)/d)+ceil((double)(y-1)/d)));
  if((n-y)%d==0)ans=min(ans,int(ceil((double)(n-x)/d)+ceil((double)(n-y)/d)));
  if(ans==1000000000)puts("-1");
  else printf("%d\n",ans);
 }
 return 0;
}
