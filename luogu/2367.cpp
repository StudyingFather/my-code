#include <cstdio>
#include <algorithm>
using namespace std;
int a[5000005],diff[5000005],n,p,mina;
int main()
{
 scanf("%d%d",&n,&p);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  diff[i]=a[i]-a[i-1];
 }
 for(int i=1;i<=p;i++)
 {
  int x,y,z;
  scanf("%d%d%d",&x,&y,&z);
  diff[x]+=z;
  diff[y+1]-=z;
 }
 mina=diff[1];
 for(int i=1;i<=n;i++)
 {
  a[i]=a[i-1]+diff[i];
  mina=min(a[i],mina);
 }
 printf("%d",mina);
 return 0;
}
