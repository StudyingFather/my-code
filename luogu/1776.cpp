#include <cstdio>
#include <algorithm>
using namespace std;
int f[40005],que[40005],que2[40005];
int main()
{
 int n,w,ans=0;
 scanf("%d%d",&n,&w);
 for(int i=1;i<=n;i++)
 {
  int v,c,m;
  scanf("%d%d%d",&v,&c,&m);
  if(!c)
  {
   ans+=v*m;
   continue;
  }
  int maxm=min(m,w/c);
  for(int j=0;j<c;j++)
  {
   int maxn=(w-j)/c,h=0,t=0;
   for(int k=0;k<=maxn;k++)
   {
    int cur=f[j+k*c]-k*v;
    while(h<t&&cur>=que[t-1])
     t--;
    que[t]=cur;
    que2[t]=k;
    t++;
    while(h<t&&que2[h]+maxm<k)
     h++;
    f[j+k*c]=max(f[j+k*c],que[h]+k*v);
   }
  }xor
 }
 printf("%d\n",f[w]+ans);
 return 0;
}