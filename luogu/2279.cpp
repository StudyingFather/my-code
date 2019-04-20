#include <cstdio>
#include <algorithm>
using namespace std;
int fa[1005],dep[1005],a[1005],b[1005],ans,n;
bool cmp(int a,int b)
{
 return dep[a]>dep[b];
}
int main()
{
 scanf("%d",&n);
 a[1]=1,b[0]=b[1]=1005;
 for(int i=2;i<=n;i++)
 {
  scanf("%d",&fa[i]);
  dep[i]=dep[fa[i]]+1;
  a[i]=i;
  b[i]=1005;
 }
 sort(a+1,a+n+1,cmp);
 for(int i=1;i<=n;i++)
 {
  int cur=a[i],f=fa[cur],g=fa[fa[cur]];
  b[cur]=min(b[cur],min(b[f]+1,b[g]+2));
  if(b[cur]>2)
  {
   b[g]=0;
   ans++;
   b[fa[g]]=min(b[fa[g]],1);
   b[fa[fa[g]]]=min(b[fa[fa[g]]],2);
  }
 }
 printf("%d\n",ans);
 return 0;
}