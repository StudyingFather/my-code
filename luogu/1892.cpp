#include <cstdio>
int fa[2005];
char s[5];
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
 int n,m,ans=0;
 scanf("%d%d",&n,&m);
 for(int i=1;i<=2*n;i++)
  fa[i]=i;
 for(int i=1;i<=m;i++)
 {
  int x,y;
  scanf("%s",s);
  scanf("%d%d",&x,&y);
  if(s[0]=='E')
  {
   unionn(find(x+n),find(y));
   unionn(find(y+n),find(x));
  }
  else unionn(find(x),find(y));
 }
 for(int i=1;i<=n;i++)
  if(fa[i]==i)ans++;
 printf("%d\n",ans);
 return 0;
}