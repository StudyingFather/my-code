#include <cstdio>
#include <algorithm>
using namespace std;
int nxt[200005],cl[200005],sta[200005],c[200005],ind[200005];
int sum,ans,top,n;
void dfs(int u)
{
 cl[u]=sum;
 sta[++top]=u;
 if(!cl[nxt[u]])dfs(nxt[u]);
 else if(cl[nxt[u]]!=sum)return;
 else
 {
  int mn=c[nxt[u]];
  while(sta[top]!=nxt[u])
   mn=min(mn,c[sta[top--]]);
  ans+=mn;
 }
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&c[i]);
 for(int i=1;i<=n;i++)
  scanf("%d",&nxt[i]);
 for(int i=1;i<=n;i++)
  if(!cl[i])
  {
   sum++;
   top=0;
   dfs(i);
  }
 printf("%d\n",ans);
 return 0;
}
