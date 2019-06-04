#include <cstdio>
int gcd(int a,int b)
{
 return b==0?a:gcd(b,a%b);
}
int main()
{
 int n,ans=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  if(gcd(i,n)==1)ans++;
 printf("%d\n",ans);
 return 0;
}