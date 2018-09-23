#include <cstdio>
#include <algorithm>
using namespace std;
int n,k,a[100005],t[100005],ans;
int main()
{
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 int maxa=0,add=0;
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&t[i]);
  if(t[i])ans+=a[i];
  else add+=a[i];
  if(i-k>0&&t[i-k]==0)add-=a[i-k];
  maxa=max(add,maxa);
 }
 printf("%d",ans+maxa);
 return 0;
}
