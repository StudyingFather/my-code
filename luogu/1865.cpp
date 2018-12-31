#include <stdio.h>
int f[1000005],vis[1000005];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 for(int i=2;i<=m;i++)
  if(!vis[i])
  {
   f[i]=f[i-1]+1;
   vis[i]=1;
   for(int j=i;(long long)i*j<=m;j++)
    vis[i*j]=1;
  }
  else f[i]=f[i-1];
 while(n--)
 {
  int l,r;
  scanf("%d%d",&l,&r);
  if(l<1||l>m||r<1||r>m)puts("Crossing the line");
  else printf("%d\n",f[r]-f[l-1]);
 }
 return 0;
}
