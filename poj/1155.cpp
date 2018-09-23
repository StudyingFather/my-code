#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
 int v,w,next;
}e[6005];
int f[3005][3005],N,M,head[3005],num[3005],temp[3005];
int cnt;
void ins(int x,int y,int w)
{
 e[cnt].v=y;
 e[cnt].w=w;
 e[cnt].next=head[x];
 head[x]=cnt++;
}
void dfs(int u)
{
 if(u>N-M)return;
 for(int i=head[u];~i;i=e[i].next)
 {
  int v=e[i].v;
  dfs(v);
  for(int k=0; k<=num[u];k++)
   temp[k]=f[u][k];
  for(int j=0; j<=num[u];j++)
   for(int k=1; k<=num[v];k++)
    f[u][j+k]=max(f[u][j+k],temp[j]+f[v][k]-e[i].w);
  num[u]+=num[v];
 }
}
int main()
{
 memset(head,-1,sizeof(head));
 scanf("%d%d",&N,&M);
 for(int i=0;i<=N;i++)
  for(int j=1;j<=N;j++)
   f[i][j]=-INF;
 memset(num,0,sizeof(num));
 for(int i=1;i<=N-M;i++)
 {
  int n;
  scanf("%d",&n);
  while(n--)
  {
   int a,b;
   scanf("%d%d",&a,&b);
   ins(i,a,b);
  }
 }
 for(int i=N-M+1;i<=N;i++)
 {
  scanf("%d",&f[i][1]);
  num[i]=1;
 }
 dfs(1);
 for(int i=M;i>=0;i--)
  if(f[1][i]>=0)
  {
   printf("%d\n",i);
   break;
  }
 return 0;
}
