#include <cstdio>
#include <algorithm>
using namespace std;
int a[200005],b[200005];
int vis[200005];
int main()
{
 int n;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  scanf("%d",&b[i]);
 int cur=1,used=0;
 for(int i=1;cur<=n;i++)
  if(vis[b[cur]])printf("0 "),cur++;
  else if(a[i]!=b[cur])vis[a[i]]=1;
  else
  {
   printf("%d ",i-used);
   vis[a[i]]=1;
   used=i;
   while(vis[b[++cur]])
    printf("0 ");
  }
 return 0;
}
