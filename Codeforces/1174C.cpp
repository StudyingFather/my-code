#include <cstdio>
#include <algorithm>
using namespace std;
int vis[100005];
int main()
{
 int n,cnt=0;
 scanf("%d",&n);
 for(int i=2;i<=n;i++)
 {
  if(!vis[i])
  {
   vis[i]=++cnt;
   for(int j=i;j<=n;j+=i)
    vis[j]=cnt;
  }
 }
 for(int i=2;i<=n;i++)
  printf("%d ",vis[i]);
 return 0;
}