#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005],pre[100005],post[100005];
int gcd(int a,int b)
{
 return b==0?a:gcd(b,a%b);
}
int main()
{
 int n,ans=1;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 pre[1]=a[1],post[n]=a[n];
 for(int i=1;i<=n;i++)
  pre[i]=gcd(pre[i-1],a[i]);
 for(int i=n-1;i;i--)
  post[i]=gcd(post[i+1],a[i]);
 for(int i=1;i<=n;i++)
  ans=max(ans,gcd(pre[i-1],post[i+1]));
 printf("%d\n",ans);
 return 0;
}