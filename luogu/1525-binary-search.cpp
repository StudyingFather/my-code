/*
 Name: luogu P1525 (binary search solution)
 Author: StudyingFather
 Date: 2019/09/03 19:30
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct edge
{
 int v,w,next;
}e[200005];
int head[20005],w[100005],col[20005],n,m,cnt;
void addedge(int u,int v,int w)
{
 e[++cnt].v=v;
 e[cnt].w=w;
 e[cnt].next=head[u];
 head[u]=cnt;
}
bool dfs(int u,int w,int c)
{
 col[u]=c;
 for(int i=head[u];i;i=e[i].next)
  if(e[i].w>w)
  {
   if(col[e[i].v]==-1)
   {
    if(!dfs(e[i].v,w,!c))return false;
   }
   else if(col[u]==col[e[i].v])return false;
  }
 return true;
}
bool check(int w)
{
 bool flag=true;
 memset(col,-1,sizeof(col));
 for(int i=1;i<=n;i++)
  if(col[i]==-1)flag&=dfs(i,w,0);
 return flag;
}
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d%d",&u,&v,&w[i]);
  addedge(u,v,w[i]);
  addedge(v,u,w[i]);
 }
 sort(w+1,w+m+1);
 int l=0,r=w[m];
 while(l<r)
 {
  int mid=(l+r)>>1;
  if(check(mid))r=mid;
  else l=mid+1;
 }
 printf("%d\n",l);
 return 0;
}