#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[65],vis[65],cnt,l;
bool cmp(int a,int b)
{
 return a>b;
}
bool dfs(int s,int c,int last)
{
 if(s>cnt)return true;
 if(c==l)return dfs(s+1,0,1);
 int flag=0;
 for(int i=last;i<=n;i++)
  if(!vis[i]&&c+a[i]<=l&&flag!=a[i])
  {
   vis[i]=1;
   if(dfs(s,c+a[i],i+1))return true;
   flag=a[i];
   vis[i]=0;
   if(c==0)return false;
  }
 return false;
}
int main()
{
 while(~scanf("%d",&n)&&n)
 {
  int sum=0,maxa=0;
  memset(a,0,sizeof(a));
  for(int i=1;i<=n;i++)
  {
   scanf("%d",&a[i]);
   sum+=a[i];
   maxa=max(maxa,a[i]);
  }
  sort(a+1,a+n+1,cmp);
  for(l=maxa;l<=sum;l++)
   if(sum%l==0)
   {
    cnt=sum/l;
    memset(vis,0,sizeof(vis));
    if(dfs(1,0,1))
    {
     printf("%d\n",l);
     break;
    }
   }
 }
 return 0;
}
