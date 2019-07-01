#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dist[35][35],n;
int main()
{
 while((~scanf("%d",&n))&&n)
 {
  memset(dist,0,sizeof(dist));
  for(int i=1;i<n;i++)
   for(int j=i+1;j<=n;j++)
    scanf("%d",&dist[i][j]);
  int ans=dist[1][2];
  for(int i=3;i<=n;i++)
  {
   int res=0x3f3f3f3f;
   for(int j=2;j<i;j++)
    res=min(res,(dist[1][i]-dist[1][j]+dist[j][i])/2);
   ans+=res;
  }
  printf("%d\n",ans);
 }
 return 0;
}