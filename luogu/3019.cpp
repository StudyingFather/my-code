#include <stdio.h>
#include <string.h>
int fa[1005],t[1005];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=2;i<=n;i++)
  scanf("%d",&fa[i]);
 for(int i=1;i<=m;i++)
 {
  memset(t,0,sizeof(t));
  int u,v;
  scanf("%d%d",&u,&v);
  int a=u,b=v;
  while(1)//向上走，记录路径
  {
   t[a]=1;
   if(a==1)break;
   a=fa[a];
  }
  while(1)
  {
   if(t[b]==1)//两者路径最早相交之处，即为最近公共祖先
   {
   	printf("%d\n",b);
   	break;
   }
   b=fa[b];
  }
 }
 return 0;
}
