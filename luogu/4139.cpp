/*
 Name: luogu P4139
 Author: StudyingFather
 Date: 2019/10/17 21:20
 Website: https://studyingfather.com
*/
#include <cstdio>
#define MAXP 10000000
int phi[10000005],p[10000005],vis[10000005],cnt;
int fpow(long long x,int y,int p)
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
int f(int x)
{
 if(x==1)return 0;
 return fpow(2,f(phi[x])+phi[x],x);
}
int main()
{
 phi[1]=1;
 for(int i=2;i<=MAXP;i++)
 {
  if(!vis[i])p[++cnt]=i,phi[i]=i-1;
  for(int j=1;j<=cnt&&i*p[j]<=MAXP;j++)
  {
   vis[i*p[j]]=1;
   if(i%p[j]==0)
   {
    phi[i*p[j]]=phi[i]*p[j];
    break;
   }
   else
    phi[i*p[j]]=phi[i]*phi[p[j]];
  }
 }
 int t;
 scanf("%d",&t);
 while(t--)
 {
  int x;
  scanf("%d",&x);
  printf("%d\n",f(x));
 }
 return 0;
}