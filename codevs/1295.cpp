#include <stdio.h>
bool a[100005],b[1000005],c[100005];
int d[100005];
bool p;
int n,ans=0;
void dfs(int dep)
{
 if(dep==n+1)ans++;
 else
  for(int i=1;i<=n;i++)
   if(!a[i]&&!b[dep-i+n]&&!c[dep+i])
   {
    a[i]=true;
    b[dep-i+n]=true;
    c[dep+i]=true;
    d[dep]=i;
    dfs(dep+1);
    a[i]=false;
    b[dep-i+n]=false;
    c[dep+i]=false;
   }
}
int main()
{
 int dep=1;
 scanf("%d",&n);
 dfs(dep);
 printf("%d",ans);
 return 0;
}
