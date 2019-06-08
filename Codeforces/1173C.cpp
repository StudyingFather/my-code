#include <cstdio>
#include <algorithm>
using namespace std;
int a[200005],b[200005],res1[200005],res2[200005],pos[200005],n;
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  res1[i]=n-i+1;
 }
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&b[i]);
  res2[b[i]]=i;
  pos[b[i]]=i;
 }
 int flag=1;
 for(int i=2;i<=n;i++)
  if(res2[1]<=res1[i]+res2[i]&&pos[i]-pos[1]!=i-1)
  {
   flag=0;
   break;
  }
 if(pos[1]==0)flag=0;
 if(!flag)
 {
  int ans=0;
  for(int i=1;i<=n;i++)
   ans=max(ans,res1[i]+res2[i]);
  printf("%d\n",ans);
 }
 else
 {
  int ans=0;
  for(int i=1;i<=n;i++)
   if(i>b[i])ans=max(ans,i-b[i]);
  printf("%d\n",ans);
 }
 return 0;
}