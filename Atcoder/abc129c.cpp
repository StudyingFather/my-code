#include <cstdio>
#define MOD 1000000007
int f[100005],t[100005],n,m;
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=m;i++)
 {
  int x;
  scanf("%d",&x);
  t[x]=1;
 }
 f[0]=1;
 if(!t[1])f[1]=1;
 for(int i=2;i<=n;i++)
  if(!t[i])f[i]=(f[i-1]+f[i-2])%MOD;
 printf("%d\n",f[n]);
 return 0;
}