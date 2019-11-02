/*
 Name: loj 161
 Author: StudyingFather
 Date: 2019/10/24 23:39
 Website: https://studyingfather.com
*/
#include <cstdio>
#define MOD 1000000007
#define NUM 998244353
int a[5000005];
long long s[50000005],sv[5000005];
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
  if(y&1)ans=ans*x%MOD;
  x=x*x%MOD;
  y>>=1;
 }
 return ans;
}
int main()
{
 int n=read();
 s[0]=1;
 for(int i=1;i<=n;i++)
 {
  a[i]=read();
  s[i]=s[i-1]*a[i]%MOD;
 }
 sv[n]=fpow(s[n],MOD-2);
 for(int i=n;i;i--)
  sv[i-1]=sv[i]*a[i]%MOD;
 long long ans=0;
 for(int i=1;i<=n;i++)
 {
  long long inv=sv[i]*s[i-1]%MOD;
  ans=(NUM*ans+inv)%MOD;
 }
 printf("%d\n",int(ans));
 return 0;
}