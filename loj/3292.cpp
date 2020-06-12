#include <cstdio>
#include <algorithm>
#define MOD 1000000009
using namespace std;
int f[2][30005];
char s[30005];
int main()
{
 int n;
 scanf("%d",&n);
 scanf("%s",s+1);
 f[0][0]=1;
 for(int i=1;i<=n;i++)
 {
  int p=i&1,q=p^1,maxj=min(i,n-i);
  for(int j=0;j<=maxj;j++)
   if(s[i]=='(')
   {
    if(!j)f[p][0]=f[q][1];
    else f[p][j]=(f[q][j-1]+f[q][j+1])%MOD;
   }
   else
    f[p][j]=f[q][j+1];
 }
 printf("%d\n",f[n&1][0]);
 return 0;
}