#include <stdio.h>
int n,a[150005],f1[150005],f2[150005],pwp[150005],vis[150005];
int find1(int x)
{
 return f1[x]==x?x:f1[x]=find1(f1[x]);
}
int find2(int x)
{
 return f2[x]==x?x:f2[x]=find2(f2[x]);
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++) 
  f1[i]=f2[i]=i;
 for(int i=1;i<n;i++)
 {
  int x,y;
  scanf("%d%d",&x,&y);
  int a=find2(x),b=find1(y);
  pwp[a]=b,f1[b]=a,f2[a]=b;
 }
 for(int i=1;i<=n;i++)
  vis[pwp[i]]=1;
 for(int i=1;i<=n;i++)
  if(!vis[i])
  {
   int u=i;
   for(int j=1;j<=n;j++)
   {
    printf("%d ",u);
    u=pwp[u];
   }
   return 0;
  }
}