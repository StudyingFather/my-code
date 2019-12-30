#include <cstdio>
struct dsu
{
 int fa[16005];
 void init(int x)
 {
  for(int i=0;i<x;i++)
   fa[i]=i;
 }
 int find(int x)
 {
  return fa[x]==x?x:fa[x]=find(fa[x]);
 }
 void unionn(int x,int y)
 {
  x=find(x),y=find(y);
  fa[y]=x;
 }
}s;
int vis[16005];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 s.init(n*2);
 while(m--)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  x--,y--;
  s.unionn(x,y^1);
  s.unionn(x^1,y);
 }
 for(int i=0;i<2*n;i+=2)
  if(s.find(i)==s.find(i^1))
  {
   puts("NIE");
   return 0;
  }
 for(int i=0;i<2*n;i++)
 {
  if(vis[i^1])continue;
  vis[i]=1;
  int x=s.find(i);
  for(int j=1;j<=2*n;j++)
   if(!vis[j^1]&&x==s.find(j))vis[j]=1;
 }
 for(int i=0;i<2*n;i++)
  if(vis[i])printf("%d\n",i+1);
 return 0;
}