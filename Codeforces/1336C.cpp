#include <cstdio>
#include <cstring>
#define MOD 998244353
int f[3005][3005];
char s[3005],t[3005];
int main()
{
 int ans=0;
 scanf("%s",s+1);
 scanf("%s",t+1);
 int n=strlen(s+1),m=strlen(t+1);
 for(int i=1;i<=n;i++)
  if(i>m||s[1]==t[i])f[i][i]=2;
 for(int i=2;i<=n;i++)
  for(int l=1;l+i-1<=n;l++)
  {
   int r=l+i-1;
   if(l>m||s[i]==t[l])f[l][r]=(f[l][r]+f[l+1][r])%MOD;
   if(r>m||s[i]==t[r])f[l][r]=(f[l][r]+f[l][r-1])%MOD;
  }
 for(int i=m;i<=n;i++)
  ans=(ans+f[1][i])%MOD;
 printf("%d\n",ans);
 return 0;
}