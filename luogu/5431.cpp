/*
 Name: luogu P5431
 Author: StudyingFather
 Date: 2019/10/24 23:59
 Website: https://studyingfather.com
*/
#include <cstdio>
int a[5000005],n,p,k;
long long s[5000005],sv[5000005];
int read()
{
 int res=0;
 char c=getchar();
 while(c<'0'||c>'9')
  c=getchar();
 while(c>='0'&&c<='9')
 {
  res=res*10+c-'0';
  c=getchar();
 }
 return res;
}
long long fpow(long long x,long long y)
{
 long long ans=1;
 while(y)
 {
  if(y&1)ans=ans*x%p;
  x=x*x%p;
  y>>=1;
 }
 return ans;
}
int main()
{
 n=read(),p=read(),k=read();
 s[0]=1;
 for(int i=1;i<=n;i++)
 {
  a[i]=read();
  s[i]=s[i-1]*a[i]%p;
 }
 sv[n]=fpow(s[n],p-2);
 for(int i=n;i;i--)
  sv[i-1]=sv[i]*a[i]%p;
 long long sk=1,ans=0;
 for(int i=1;i<=n;i++)
 {
  long long inv=sv[i]*s[i-1]%p;
  sk=sk*k%p;
  ans=(ans+sk*inv)%p;
 }
 printf("%d\n",int(ans));
 return 0;
}