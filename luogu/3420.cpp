#include <stdio.h>
int fa[1000005];
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
 fa[y]=x;
}
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  fa[i]=i;
 for(int i=1;i<=n;i++)
 {
  int x;
  scanf("%d",&x);
  unionn(find(i),find(x));
 }
 for(int i=1;i<=n;i++)
  if(fa[i]==i)ans++;
 printf("%d\n",ans);
 return 0;
}