#include <cstdio>
#include <algorithm>
using namespace std;
int t[100005],sum[100005];
int main()
{
 int n,w;
 scanf("%d%d",&n,&w);
 for(int i=1;i<=n;i++)
 {
  int x,b;
  scanf("%d%d",&x,&b);
  t[x]+=b;
 }
 for(int i=1;i<=100000;i++)
  sum[i]=sum[i-1]+t[i];
 int ans=0;
 for(int i=w;i<=100000;i++)
  ans=max(ans,sum[i]-sum[i-w]);
 printf("%d\n",ans);
 return 0;
}