#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t[200005],vis[200005],cyc[200005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&t[i]);
 int ans=200005;
 for(int i=1;i<=n;i++)
 {
  if(vis[i]==-1)continue;
  memset(cyc,0,sizeof(cyc));
  cyc[1]=i;
  vis[i]=1;
  int cnt=1,cur=i;
  while(1)
  {
   cur=t[cur];
   cyc[++cnt]=cur;
   if(vis[cur]==-1)
   {
    for(int i=1;i<=cnt;i++)
     vis[cyc[i]]=-1;
    break;
   }
   if(vis[cur]>0)
   {
    ans=min(ans,cnt-vis[cur]);
    for(int i=1;i<=cnt;i++)
     vis[cyc[i]]=-1;
    break;
   }
   vis[cur]=cnt;
  }
 }
 printf("%d\n",ans);
 return 0;
}