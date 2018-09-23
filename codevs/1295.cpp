#include <stdio.h>
bool a[100000],b[1000000],c[100000];
int d[100000];
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
