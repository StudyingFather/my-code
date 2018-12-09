#include <stdio.h>
int fa[10005];
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
 int n,m;
 scanf("%d%d",&n,&m);
 if(m!=n-1)
 {
  puts("NO");
  return 0;
 }
 for(int i=1;i<=n;i++)
  fa[i]=i;
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  if(find(u)!=find(v))unionn(find(u),find(v));
  else
  {
   puts("NO");
   return 0;
  }
 }
 puts("YES");
 return 0;
}
