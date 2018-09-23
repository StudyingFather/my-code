#include <cstdio>
#include <algorithm>
#include <cmath>
#define INF 2000000000
using namespace std;
int mv[105],ms[105],ans=INF,r[105],h[105];
int n,m;
void dfs(int now,int s,int v,int lr,int lh)
{
 if(now==0)
 {
  if(v==n)ans=min(ans,s);
  return;
 }
 if(s+ms[now]>ans)return;
 if(v+mv[now]>n)return;
 if(s+(n-v)*2/lr>ans)return;
 int maxr=min((int)sqrt((double)n-v),lr-1);
 for(int i=maxr;i>=now;i--)
 {		
  if(now==m)s=i*i;
  int maxh=min((n-v-mv[now-1])/(i*i),lh-1);
  for(int j=maxh;j>=now;j--)
   dfs(now-1,s+2*i*j,v+i*i*j,i,j);
 }
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  mv[i]=mv[i-1]+i*i*i;
  ms[i]=ms[i-1]+2*i*i;
 }
 int maxr=sqrt((double)n);
 dfs(m,0,0,maxr,n);
 if(ans==INF)printf("0");
 else printf("%d",ans);
 return 0;
}
