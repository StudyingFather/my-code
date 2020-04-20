#include <cstdio>
#include <cstring>
int a[105][105],vis[105],n;
int f1()
{
 int ans=0;
 for(int i=1;i<=n;i++)
  ans+=a[i][i];
 return ans;
}
int f2()
{
 int ans=0;
 for(int i=1;i<=n;i++)
 {
  memset(vis,0,sizeof(vis));
  for(int j=1;j<=n;j++)
  {
   vis[a[i][j]]++;
   if(vis[a[i][j]]>1)
   {
    ans++;
    break;
   }
  }
 }
 return ans;
}
int f3()
{
 int ans=0;
 for(int i=1;i<=n;i++)
 {
  memset(vis,0,sizeof(vis));
  for(int j=1;j<=n;j++)
  {
   vis[a[j][i]]++;
   if(vis[a[j][i]]>1)
   {
    ans++;
    break;
   }
  }
 }
 return ans;
}
int main()
{
 int t;
 scanf("%d",&t);
 for(int kase=1;kase<=t;kase++)
 {
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
   for(int j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
  printf("Case #%d: %d %d %d\n",kase,f1(),f2(),f3());
 }
 return 0;
}