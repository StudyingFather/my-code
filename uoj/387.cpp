#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct edge
{
 int v,next;
}e[100005];
struct node
{
 int x,siz;
 bool operator<(const node&a)const
 {
  return siz<a.siz;
 }
};
int head[100005],cnt,siz[100005],topush[100005],num[100005];
priority_queue<node> q;
vector<int> res[100005];
void addedge(int u,int v)
{
 e[++cnt].v=v;
 e[cnt].next=head[u];
 head[u]=cnt;
}
void dfs(int x)
{
 siz[x]=1;
 for(int i=head[x];i;i=e[i].next)
 {
  dfs(e[i].v);
  siz[x]+=siz[e[i].v];
 }
}
int main()
{
 int n,m,ans=1;
 scanf("%d%d",&n,&m);
 for(int i=2;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  addedge(x,i);
 }
 dfs(1);
 q.push({1,n});
 while(!q.empty())
 {
  num[ans]=min((int)q.size(),m);
  int pushnum=0;
  for(int i=1;i<=num[ans];i++)
  {
   node u=q.top();
   q.pop();
   res[ans].push_back(u.x);
   for(int j=head[u.x];j;j=e[j].next)
    topush[++pushnum]=e[j].v;
  }
  for(int i=1;i<=pushnum;i++)
   q.push({topush[i],siz[topush[i]]});
  ans++;
 }
 ans--;
 printf("%d\n",ans);
 for(int i=1;i<=ans;i++)
 {
  printf("%d ",num[i]);
  for(int j=0;j<num[i];j++)
   printf("%d ",res[i][j]);
  puts("");
 }
 return 0;
}