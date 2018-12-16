#include <cstdio>
#include <algorithm>
using namespace std;
int fa[2005];
int find(int x)
{
 int cnt=0;
 while(x!=-1)
  x=fa[x],cnt++;
 return cnt;
}
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&fa[i]);
 for(int i=1;i<=n;i++)
  ans=max(ans,find(i));
 printf("%d\n",ans);
 return 0;
}
