#include <stdio.h>
int fa[10005];
int find(int a)
{
 return a==fa[a]?a:fa[a]=find(fa[a]);
}
void unionn(int a,int b)
{
 fa[find(a)]=find(b);
}
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
  fa[i]=i;
 for(int i=1;i<=m;i++)
 {
  int z,x,y;
  scanf("%d%d%d",&z,&x,&y);
  if(z==1)
   if(find(x)!=find(y))unionn(x,y);
  if(z==2)
  {
   if(find(x)==find(y))puts("Y");
   else puts("N");
  }
 }
 return 0;
}
