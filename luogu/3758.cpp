/*
 Name: luogu P3758
 Author: StudyingFather
 Date: 2019/08/06 09:45
 Website: https://studyingfather.com
*/
#include <cstdio>
#include <cstring>
#define MOD 2017
struct mat
{
 int a[35][35];
 mat()
 {
  memset(a,0,sizeof(a));
 }
}f;
int n,m,t;
mat init()
{
 mat tmp;
 for(int i=0;i<=n;i++)
  tmp.a[i][i]=1;
 return tmp;
}
mat operator*(mat a,mat b)
{
 mat ans;
 for(int k=0;k<=n;k++)
  for(int i=0;i<=n;i++)
   for(int j=0;j<=n;j++)
    ans.a[i][j]=(ans.a[i][j]+a.a[i][k]*b.a[k][j])%MOD;
 return ans;
}
mat fpow(mat x,int y)
{
 mat ans=init();
 while(y)
 {
  if(y&1)ans=ans*x;
  x=x*x;
  y>>=1;
 }
 return ans;
}
int main()
{
 scanf("%d%d",&n,&m);
 f=init();
 for(int i=1;i<=m;i++)
 {
  int u,v;
  scanf("%d%d",&u,&v);
  f.a[u][v]=f.a[v][u]=1;
 }
 for(int i=1;i<=n;i++)
  f.a[i][0]=1;
 scanf("%d",&t);
 mat res=fpow(f,t);
 int ans=0;
 for(int i=0;i<=n;i++)
  ans=(ans+res.a[1][i])%MOD;
 printf("%d\n",ans);
 return 0;
}