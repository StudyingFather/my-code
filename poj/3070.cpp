#include <stdio.h>
#define MOD 10000
struct mat
{
 int a[2][2];
}a,ans,tmp;
inline mat mat_c(mat x,mat y)
{
 for(int i=0;i<2;i++)
  for(int j=0;j<2;j++)
  {
   tmp.a[i][j]=0;
   for(int k=0;k<2;k++)
   {
    tmp.a[i][j]+=(x.a[i][k]*y.a[k][j])%10000;
    tmp.a[i][j]%=10000;
   }
  }
 return tmp;
}
int main()
{
 int n;
 while((~scanf("%d",&n))&&n!=-1)
 {
  if(n==0)
  {
   printf("0\n");
   continue;
  }
  a.a[0][0]=1,a.a[0][1]=1,a.a[1][0]=1,a.a[1][1]=0;
  ans.a[0][0]=1,ans.a[0][1]=0,ans.a[1][0]=0,ans.a[1][1]=1;
  n--;
  while(n)
  {
   if(n%2)ans=mat_c(ans,a);
   a=mat_c(a,a);
   n>>=1;
  }
  printf("%d\n",ans.a[0][0]);
 }
 return 0;
}
