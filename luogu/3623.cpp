/*
 Name: luogu P3623
 Author: StudyingFather
 Date: 2019/10/23 18:42
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int u,v,w;
}e[100005];
int fa[20005],res[100005];
bool cmp1(const edge&a,const edge&b)
{
 return a.w>b.w;
}
bool cmp2(const edge&a,const edge&b)
{
 return a.w<b.w;
}
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
 fa[x]=y;
}
int main()
{
 int n,m,k;
 scanf("%d%d%d",&n,&m,&k);
 for(int i=1;i<=m;i++)
  scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
 for(int i=1;i<=n;i++)
  fa[i]=i;
 sort(e+1,e+m+1,cmp1);
 int cnt=0;
 for(int i=1;i<=m;i++)
  if(find(e[i].u)!=find(e[i].v))
  {
   unionn(find(e[i].u),find(e[i].v));
   if(!e[i].w)cnt++,e[i].w=-1;
  }
 if(cnt>k)
 {
  puts("no solution");
  return 0;
 }
 for(int i=1;i<=n;i++)
  fa[i]=i;
 sort(e+1,e+m+1,cmp2);
 cnt=0;
 for(int i=1;i<=m;i++)
 if(find(e[i].u)!=find(e[i].v))
  {
   if(e[i].w!=1)
   {
    if(k)k--;
    else continue;
   }
   unionn(find(e[i].u),find(e[i].v));
   res[++cnt]=i;
   if(e[i].w==-1)e[i].w=0;
   if(cnt==n-1)break;
  }
 if(cnt<n-1||k)
 {
  puts("no solution");
  return 0;
 }
 for(int i=1;i<n;i++)
  printf("%d %d %d\n",e[res[i]].u,e[res[i]].v,e[res[i]].w);
 return 0;
}