#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;
int d[10005],u[10005],x[10005],y[10005],f[10005][2005];
set<int> s;
int main()
{
 int n,m,k;
 scanf("%d%d%d",&n,&m,&k);
 for(int i=1;i<=n;i++)
 {
  scanf("%d%d",&x[i],&y[i]);
  d[i]=1;
  u[i]=m;
 }
 for(int i=1;i<=k;i++)
 {
  int p,l,h;
  scanf("%d%d%d",&p,&l,&h);
  d[p]=l+1,u[p]=h-1;
  s.insert(p);
 }
 memset(f,INF,sizeof(f));
 for(int i=1;i<=m;i++)
  f[0][i]=0;
 for(int i=1;i<=n;i++)
 {
  for(int j=x[i]+1;j<=x[i]+m;j++)
   f[i][j]=min(f[i-1][j-x[i]]+1,f[i][j-x[i]]+1);
  for(int j=m+1;j<=x[i]+m;j++)
   f[i][m]=min(f[i][j],f[i][m]);
  for(int j=1;j<=m-y[i];j++)
   f[i][j]=min(f[i][j],f[i-1][j+y[i]]);
  for(int j=1;j<d[i];j++)
   f[i][j]=INF;
  for(int j=u[i]+1;j<=m;j++)
   f[i][j]=INF;
 }
 int ans=INF;
 for(int i=1;i<=m;i++)
  ans=min(ans,f[n][i]);
 if(ans!=INF)printf("1\n%d\n",ans);
 else
 {
  ans=0;
  for(int i=1;i<=n;i++)
  {
   int tmp=INF;
   for(int j=1;j<=m;j++)
    tmp=min(f[i][j],tmp);
   if(tmp==INF)
   {
    printf("0\n%d\n",ans);
    break;
   }
   ans+=s.count(i);
  }
 }
 return 0;
}