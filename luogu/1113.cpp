#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[10005];
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
  int num,t,pret;
  scanf("%d%d",&num,&t);
  while((~scanf("%d",&pret))&&pret)
   f[i]=max(f[i],f[pret]);
  if(f[i]==0x3f3f3f3f)f[i]=0;
  f[i]+=t;
  ans=max(ans,f[i]);
 }
 printf("%d",ans);
 return 0;
}