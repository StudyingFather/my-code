#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005];
int main()
{
 int n,m,c;
 scanf("%d%d%d",&n,&m,&c);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 sort(a+1,a+n+1);
 int l=0,r=a[n]-a[1];
 while(l<r)
 {
  int mid=(l+r)>>1,cnt=1,sta=1;
  for(int i=1;i<=n;i++)
   if(a[i]-a[sta]>mid||i-sta+1>c)
   {
    cnt++;
    sta=i;
   }
  if(cnt<=m)r=mid;
  else l=mid+1;
 }
 printf("%d\n",l);
 return 0;
}