#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int n,tmp,ans,kase;
int t[1005],b[1005],f[1005][265][20];
int main()
{
 scanf("%d",&kase);
 while(kase--)
 {
  scanf("%d",&n);  
  for(int i=1;i<=n;i++)
   scanf("%d%d",&t[i],&b[i]);
  memset(f,INF,sizeof(f));
  f[1][0][7]=0;
  ans=INF;
  for(int i=1;i<=n;i++)
   for(int j=0;j<(1<<8);j++)
    for(int k=-8;k<=7;k++)
     if(f[i][j][k+8]<INF)
     {
      if(j&1)f[i+1][j>>1][k+7]=min(f[i+1][j>>1][k+7],f[i][j][k+8]);
      else
      {
       tmp=INF;
       for(int h=0;h<=7;h++)
        if(!((j>>h)&1))
        {
         if(i+h>tmp) break;
         tmp=min(tmp,i+h+b[i+h]);
         f[i][j|(1<<h)][h+8]=min(f[i][j|(1<<h)][h+8],f[i][j][k+8]+(i+k?(t[i+k]^t[i+h]):0));
        }
      }
     }
  for(int k=0;k<=8;k++)
   ans=min(ans,f[n+1][0][k]);
  printf("%d\n",ans);
 }
 return 0;
}