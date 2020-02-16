#include <cstdio>
#include <algorithm>
#define MOD 1000000007
using namespace std;
char s[1005],t[205];
int f[1005][1005],g[1005][1005];
int main()
{
 int n,m,k;
 scanf("%d%d%d",&n,&m,&k);
 scanf("%s%s",s+1,t+1);
 g[0][0]=1;
 for(int i=1;i<=n;i++)
  for(int j=min(m,i);j;j--)
   for(int p=min(k,j);p;p--)
   {
    if(s[i]==t[j])f[j][p]=(f[j-1][p]+g[j-1][p-1])%MOD;
    else f[j][p]=0;
    g[j][p]=(g[j][p]+f[j][p])%MOD;
   }
 printf("%d\n",g[m][k]);
 return 0;
}