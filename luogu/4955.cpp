/*
 Name: luogu P4955
 Author: StudyingFather
 Date: 2019/10/14 16:39
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
 int u,v,w;
}e[500005];
const int dx[]={1,0};
const int dy[]={0,1};
int h[505][505],fa[250005],p[250005],cnte,cntp;
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
 fa[y]=x;
}
bool cmp(const edge&a,const edge&b)
{
 return a.w<b.w;
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
   scanf("%d",&h[i][j]);
   fa[(i-1)*m+j]=(i-1)*m+j;
  }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
   int x;
   scanf("%d",&x);
   if(x)p[++cntp]=(i-1)*m+j;
  }
 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   for(int k=0;k<=1;k++)
   {
    int x=i+dx[k],y=j+dy[k];
    int u=(i-1)*m+j,v=(x-1)*m+y;
    if(x<=n&&y<=m)e[++cnte]={u,v,abs(h[i][j]-h[x][y])};
   }
 sort(e+1,e+cnte+1,cmp);
 for(int i=1;;i++)
 {
  int u=e[i].u,v=e[i].v,fu=find(u),fv=find(v);
  if(fu!=fv)unionn(fu,fv);
  else continue;
  int f=find(p[1]);
  bool flag=true;
  for(int i=2;i<=cntp;i++)
   if(f!=find(p[i]))
   {
    flag=false;
    break;
   }
  if(flag)
  {
   printf("%d\n",e[i].w);
   return 0;
  }
 }
}