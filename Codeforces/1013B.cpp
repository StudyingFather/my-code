#include <cstdio>
#include <algorithm>
using namespace std;
int n,x,a[100005],t1[100005],t2[100005],ans=3;
int main()
{
 scanf("%d%d",&n,&x);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  t1[a[i]]++;
  if(t1[a[i]]>1)ans=0;
 }
 for(int i=1;i<=n;i++)
 {
  int num=a[i];
  num&=x;
  if(num!=a[i])t1[num]++;
  if(t1[num]>1)ans=min(ans,1);
  if(num!=a[i])t1[num]--;
  if(num!=a[i])t2[num]++;
  if(t2[num]>1)ans=min(ans,2);
 }
 if(ans==3)printf("-1");
 else printf("%d",ans);
 return 0;
}
