#include <stdio.h>
#include <string.h>
int a[100005],t[100005];
int main()
{
 int n,k,ans=1;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 int cur=0;
 while(cur<n)
 {
  memset(t,0,sizeof(t));
  int cnt=0,nexts=cur;
  while(nexts<n&&cnt<k)
  {
   nexts++;
   if(!t[a[nexts]])
   {
    t[a[nexts]]=1;
    cnt++;
   }
  }
  if(cnt==k)
  {
   ans++;
   cur=nexts;
  }
  else break;
 }
 printf("%d\n",ans);
 return 0;
}
