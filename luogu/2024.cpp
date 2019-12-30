#include <cstdio>
int fa[200005];
void unionn(int x,int y)
{
 fa[y]=x;
}
int find(int x)
{
 return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
 int n,k,ans=0;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=3*n;i++)
  fa[i]=i;
 for(int i=1;i<=k;i++)
 {
  int op,x,y;
  scanf("%d%d%d",&op,&x,&y);
  if(x>n||y>n)ans++;
  else if(op==1)
  {
   if(find(x+n)==find(y)||find(x)==find(y+n))ans++;
   else
   {
    unionn(find(x),find(y));
    unionn(find(x+n),find(y+n));
    unionn(find(x+2*n),find(y+2*n));
   }
  }
  else
  {
   if(find(x)==find(y)||find(x)==find(y+n))ans++;
   else
   {
    unionn(find(x+n),find(y));
    unionn(find(x+2*n),find(y+n));
    unionn(find(x),find(y+2*n));
   }
  }
 }
 printf("%d\n",ans);
 return 0;
}