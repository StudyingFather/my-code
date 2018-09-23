#include <cstdio>
#include <algorithm>
using namespace std;
int a[2005],b[2005],dir[2005],vis[2005];
bool cmp(int a,int b)
{
 return a>b;
}
int main()
{
 int n,k;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  b[i]=a[i];
 }
 sort(b+1,b+n+1,cmp);
 int ans=0;
 for(int i=1;i<=k;i++)
  ans+=b[i];
 printf("%d\n",ans);
 for(int i=1;i<=k;i++)
  for(int j=1;j<=n;j++)
   if(a[j]==b[i]&&(!vis[j]))
   {
   	dir[i]=j;
   	vis[j]=1;
   	break;
   }
 sort(dir+1,dir+k+1);
 for(int i=1;i<=k;i++)
  if(i!=k)printf("%d ",dir[i]-dir[i-1]);
  else printf("%d",n-dir[k-1]);
 return 0;
}
