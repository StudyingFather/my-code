#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int f[205][205],a[205],sum[205],n;
int dfs1(int l,int r)
{
 if(l==r)return 0;
 if(f[l][r])return f[l][r];
 int ans=INF;
 for(int i=l;i<r;i++)
  ans=min(ans,dfs1(l,i)+dfs1(i+1,r)+sum[r]-sum[l-1]);
 return f[l][r]=ans;
}
int dfs2(int l,int r)
{
 if(l==r)return 0;
 if(f[l][r])return f[l][r];
 int ans=0;
 for(int i=l;i<r;i++)
  ans=max(ans,dfs2(l,i)+dfs2(i+1,r)+sum[r]-sum[l-1]);
 return f[l][r]=ans;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
  a[i+n]=a[i];
 }
 for(int i=1;i<=2*n;i++)
  sum[i]=sum[i-1]+a[i];
 dfs1(1,2*n);
 int ans=INF;
 for(int i=1;i<=n;i++)
  ans=min(ans,f[i][i+n-1]);
 printf("%d\n",ans);
 memset(f,0,sizeof(f));
 dfs2(1,2*n);
 ans=0;
 for(int i=1;i<=n;i++)
  ans=max(ans,f[i][i+n-1]);
 printf("%d\n",ans);
 return 0;
}