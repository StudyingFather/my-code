#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[255],s[255],d[255];
bool vis[255];
int main()
{
 int n,b;
 scanf("%d%d",&n,&b);
 for(int i=1;i<=n;i++)
  scanf("%d",&f[i]);
 for(int i=1;i<=b;i++)
  scanf("%d%d",&s[i],&d[i]);
 vis[1]=1;
 for(int i=1;i<=b;i++)
 {
  for(int j=1;j<=n;j++)
   if(vis[j]&&s[i]>=f[j])
    for(int k=j;k<=min(n,j+d[i]);k++)
     if(s[i]>=f[k])vis[k]=true;
  if(vis[n])
  {
   printf("%d\n",i-1);
   break;
  }
 }
}