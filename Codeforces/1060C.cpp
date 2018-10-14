#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[2005],b[2005],suma[2005],sumb[2005],c[2005];
int n,m,x;
int search(int num)
{
 int l=1,r=n;
 int mid=(l+r)>>1;
 while(l<=r)
 {
  mid=(l+r)>>1;
  if((long long)c[mid]*num==x)return mid;
  if((long long)c[mid]*num<x)l=mid+1;
  else r=mid-1;
 }
 return r;
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  suma[i]=suma[i-1]+a[i];
 }
 for(int i=1;i<=m;i++)
 {
  scanf("%d",&b[i]);
  sumb[i]=sumb[i-1]+b[i];
 }
 scanf("%d",&x);
 memset(c,0x3f,sizeof(c));
 for(int i=1;i<=n;i++)
  for(int j=i;j<=n;j++)
   c[j-i+1]=min(c[j-i+1],suma[j]-suma[i-1]);
 int ans=0;
 for(int i=1;i<=m;i++)
  for(int j=i;j<=m;j++)
  {
   int res=search(sumb[j]-sumb[i-1]);
   ans=max(ans,res*(j-i+1));
  }
 printf("%d",ans);
 return 0;
}