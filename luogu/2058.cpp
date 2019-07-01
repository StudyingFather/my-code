#include <stdio.h>
#include <string.h>
#define tmax 86400
int t[300005],a[300005],b[300005],s[300005];
int main()
{
 int n,i,j,k,p,r,ans;
 scanf("%d",&n);
 r=0;
 ans=0;
 for(i=1;i<=n;i++)
 {
  scanf("%d%d",&t[i],&k);
  s[i]=s[i-1]+k;
  for(j=1;j<=k;j++)
  {
   r++;
   scanf("%d",&b[r]);
  }
 }
 memset(a,0,sizeof(a));
 p=1;
 for(i=1;i<=n;i++)
 {
  for(j=s[i-1]+1;j<=s[i];j++)
  {
   if(a[b[j]]==0)ans++;
   a[b[j]]++;
  }
  while(t[i]-t[p]>=tmax)
  {
   for(j=s[p-1]+1;j<=s[p];j++)
   {
    a[b[j]]--;
    if(a[b[j]]==0)ans--;
   }
   p++;
  }
  printf("%d\n",ans);
 }
 return 0;
}
