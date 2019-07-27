#include <cstdio>
#include <algorithm>
using namespace std;
int vis[15],res[15],c[15],n,sum,flag;
void dfs(int d,int num)
{
 if(num>sum)return;
 if(d==n)
 {
  if(num==sum)
  {
   for(int i=0;i<n;i++)
    printf("%d ",res[i]);
   flag=true;
  }
  return;
 }
 for(int i=1;i<=n;i++)
 {
  if(flag)return;
  if(!vis[i])
  {
   vis[i]=1;
   res[d]=i;
   dfs(d+1,num+i*c[d]);
   vis[i]=0;
   res[d]=0;
  }
 }
 return;
}
int main()
{
 scanf("%d%d",&n,&sum);
 c[0]=1;
 for(int i=1;i<=n;i++)
  c[i]=(n-i)*c[i-1]/i;
 dfs(0,0);
}