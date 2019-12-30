#include <cstdio>
#define MOD 10000
int f[1005][2];
int fpow(int x,int y)
{
 int ans=1;
 while(y)
 {
  if(y&1)ans=ans*x%MOD;
  x=x*x%MOD;
  y>>=1;
 }
 return ans;
}
int main()
{
 int k;
 scanf("%d",&k);
 int tot=1;
 f[0][0]=1;
 for(int i=1;i<=k;i++)
 {
  int p,e;
  scanf("%d%d",&p,&e);
  tot=tot*fpow(p,e)%MOD;
  for(int j=0;j<=1;j++)
   f[i][j]=(f[i-1][j^1]*(p==2?0:p-1)+f[i-1][j])%MOD;
 }
 f[k][0]=(f[k][0]-1+MOD)%MOD;
 printf("%d\n",f[k][0]);
 printf("%d\n",f[k][1]);
 printf("%d\n",((tot-f[k][0]-f[k][1]-1)%MOD+MOD)%MOD);
 return 0;
}