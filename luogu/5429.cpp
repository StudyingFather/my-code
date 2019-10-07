/*
 Name: luogu P5429
 Author: StudyingFather
 Date: 2019/10/05 18:56
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct dsu
{
 int fa,minx,miny,maxx,maxy;
}a[100005];
int find(int x)
{
 return a[x].fa==x?a[x].fa:a[x].fa=find(a[x].fa);
}
void unionn(int x,int y)
{
 a[y].fa=x;
 a[x].minx=min(a[x].minx,a[y].minx);
 a[x].miny=min(a[x].miny,a[y].miny);
 a[x].maxx=max(a[x].maxx,a[y].maxx);
 a[x].maxy=max(a[x].maxy,a[y].maxy);
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  a[i].fa=i;
  a[i].minx=a[i].maxx=x;
  a[i].miny=a[i].maxy=y;
 }
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  if(find(u)!=find(v))
   unionn(find(u),find(v));
 }
 int ans=2e9;
 for(int i=1;i<=n;i++)
  if(a[i].fa==i)ans=min(ans,2*((a[i].maxx-a[i].minx)+(a[i].maxy-a[i].miny)));
 printf("%d\n",ans);
 return 0;
}