#include <cstdio>
#define MOD 19260817
char s[5000005],t[5000005];
int f[35];
int main()
{
 int n,m;
 scanf("%d%d",&n,&m);
 scanf("%s",s+1);
 scanf("%s",t+1);
 int cnt=n,ans=1;
 for(int i=1;i<=m;i++)
 {
  if(t[i]>='A'&&t[i]<='Z')
  {
   int res=f[t[i]-'A'];
   f[t[i]-'A']=ans;
   ans=((2*ans-res)%MOD+MOD)%MOD;
  }
  else
  {
   if(!cnt)continue;
   f[s[cnt]-'A']=(f[s[cnt]-'A']+1)%MOD;
   ans=(ans+1)%MOD;
   cnt--;
  }
 }
 printf("%d\n",ans);
 return 0;
}