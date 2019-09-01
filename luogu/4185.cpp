/*
 Name: luogu P4185
 Author: StudyingFather
 Date: 2019/08/09 19:19
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int u,v,w;
}e[100005];
struct query
{
 int k,v,id;
}a[100005];
int fa[100005],siz[100005],ans[100005];
bool cmp1(const edge&a,const edge&b)
{
 return a.w>b.w;
}
bool cmp2(const query&a,const query&b)
{
 return a.k>b.k;
}
void unionn(int x,int y)
{
 if(x==y)return;
 fa[y]=x;
 siz[x]+=siz[y];
}
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
 int n,q;
 scanf("%d%d",&n,&q);
 for(int i=1;i<=n;i++)
  fa[i]=i,siz[i]=1;
 for(int i=1;i<n;i++)
  scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
 for(int i=1;i<=q;i++)
 {
  scanf("%d%d",&a[i].k,&a[i].v);
  a[i].id=i;
 }
 sort(e+1,e+n,cmp1);
 sort(a+1,a+q+1,cmp2);
 int cur=1;
 for(int i=1;i<=q;i++)
 {
  while(cur<=n&&a[i].k<=e[cur].w)
  {
   unionn(find(e[cur].u),find(e[cur].v));
   cur++;
  }
  ans[a[i].id]=siz[find(a[i].v)]-1;
 }
 for(int i=1;i<=q;i++)
  printf("%d\n",ans[i]);
 return 0;
}