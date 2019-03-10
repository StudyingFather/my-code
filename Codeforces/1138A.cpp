#include <cstdio>
#include <algorithm>
using namespace std;
int a[100005];
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 int cur=a[1],cnt1=0,cnt2=0;
 if(cur==1)cnt1=1;
 else cnt2=1;
 for(int i=2;i<=n;i++)
  if(a[i]!=cur)
  {
   ans=max(ans,min(cnt1,cnt2));
   if(cur==1)cnt2=1;
   else cnt1=1;
   cur=a[i];
  }
  else
  {
   if(cur==1)cnt1++;
   else cnt2++;
  }
 ans=max(ans,min(cnt1,cnt2));
 printf("%d\n",ans*2);
 return 0;
}