#include <cstdio>
#include <algorithm>
#define MOD 1000000007
using namespace std;
int f[17000005],dist[17000005];
int b1,b2;
inline int lowbit(int x)
{
 return x&(-x);
}
int main()
{
 int n,m;
 scanf("%d",&n);
 for(int i=0;i<n;i++)
  scanf("%d",&dist[1<<i]);
 scanf("%d",&m);
 if(m==1)scanf("%d",&b1);
 else if(m==2)scanf("%d%d",&b1,&b2);
 f[0]=1;
 int maxx=(1<<n)-1;
 for(int i=1;i<=maxx;i++)
 {
  int x=i,y=lowbit(x);
  dist[i]=dist[i^y]+dist[y];
  if(dist[i]==b1||dist[i]==b2)continue;
  while(y)
  {
   f[i]+=f[i^y];
   if(f[i]>=MOD)f[i]-=MOD;
   x^=y;
   y=lowbit(x);
  }
 }
 printf("%d\n",f[maxx]);
 return 0;
}