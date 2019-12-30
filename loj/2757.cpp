#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int f[10005],g[10005],p[10005];
bool cmp(int x,int y)
{
 return x>y;
}
int main()
{
 int m,n;
 cin>>m>>n;
 for(int i=1;i<=m;i++)
  cin>>p[i];
 sort(p+1,p+m+1,cmp);
 for(int i=1;i<=m;i++)
  f[i]=f[i-1]+p[i];
 memset(g,63,sizeof(g));
 g[0]=0;
 for(int i=1;i<=n;i++)
 {
  int c,e;
  cin>>c>>e;
  for(int j=m;j>=0;j--)
   g[j]=min(g[j],g[max(j-c,0)]+e);
 }
 int ans=0;
 for(int i=0;i<=m;i++)
  ans=max(ans,f[i]-g[i]);
 cout<<ans<<endl;
 return 0;
}