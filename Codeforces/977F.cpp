#include <cstdio>
#include <algorithm>
using namespace std;
int f[200005],a[200005],ans;
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  f[i]=1;
 }
 for(int i=1;i<=n;i++)
  for(int j=1;j<i;j++)
  {
   if(a[i]==a[j]+1&&f[j]+1>f[i])f[i]=f[j]+1;
   if(f[i]>ans)ans=f[i];
  }
 printf("%d\n",ans);
 int maxf=0;
 for(int i=1;;i++)
  if(f[i]==maxf+1)
  {
   printf("%d ",i);
   maxf++;
   if(maxf==ans)return 0;
  }
}
