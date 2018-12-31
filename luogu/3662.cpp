#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005];
int main()
{
 int n,k,b,ans=0,cur=0;
 scanf("%d%d%d",&n,&k,&b);
 for(int i=1;i<=n;i++)
  a[i]=1;
 for(int i=1;i<=b;i++)
 {
  int x;
  scanf("%d",&x);
  a[x]=0;
 }
 for(int i=1;i<=k;i++)
  cur+=a[i];
 ans=cur;
 for(int i=2;i<=n-k+1;i++)
 {
  cur+=a[i+k-1]-a[i-1];
  ans=max(ans,cur);
 }
 printf("%d\n",k-ans);
 return 0;
}
