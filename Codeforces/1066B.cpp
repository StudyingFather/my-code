#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005],vis[1005],ans;
int main()
{
 int n,r;
 scanf("%d%d",&n,&r);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
 for(int i=1;i<=n;i++)
  if(vis[i]==0)
  {
   int flag=false;
   for(int j=min(i+r-1,n);j>=max(1,i-r+1);j--)
    if(a[j]==1)
    {
     for(int k=max(1,j-r+1);k<=min(n,j+r-1);k++)
      vis[k]=1;
     flag=true;
     ans++;
     break;
    }
   if(!flag)
   {
    puts("-1");
    return 0;
   }
  }
 printf("%d\n",ans);
 return 0;
}
