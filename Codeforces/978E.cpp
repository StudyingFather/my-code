#include <cstdio>
#include <algorithm>
#define INF 2000000005
using namespace std;
int maxp,minp,a[100005];
int main()
{
 int n,w,flag=1;
 scanf("%d%d",&n,&w);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  if(w<abs(a[i]))
  {
   flag=0;
   break;
  }
 }
 if(!flag)
 {
  printf("0");
  return 0;
 }
 if(a[1]>=0)
 {
  minp=0;
  maxp=w-a[1];
 }
 else
 {
  minp=-a[1];
  maxp=w;
 }
 int p1=maxp+a[1],p2=minp+a[1];
 for(int i=2;i<=n;i++)
 {
  if(p1+a[i]>w)
  {
   maxp-=p1+a[i]-w;
   p1=w-a[i];
  }
  p1+=a[i];
  if(p2+a[i]<0)
  {
   minp+=abs(p2+a[i]);
   p2=-a[i];
  }
  p2+=a[i];
 }
 if(maxp<minp)printf("0");
 else printf("%d",maxp-minp+1);
 return 0;
}
