#include <cstdio>
#include <algorithm>
#define INF 0x7f7f7f7f
using namespace std;
int a1[30005],a2[30005];
int main()
{
 int n,maxc=0,m1,m2,ans=INF;
 scanf("%d",&n);
 scanf("%d%d",&m1,&m2);
 if(m1==1)
 {
  puts("0");
  return 0;
 }
 int cur=2;
 while(m1!=1)
 {
  while(m1%cur==0)
  {
   m1/=cur;
   a1[cur]++;
  }
  if(a1[cur])maxc=cur;
  a1[cur]*=m2;
  cur++;
 }
 for(int i=1;i<=n;i++)
 {
  int num,t=0,flag=0,res=0;
  scanf("%d",&num);
  for(int j=2;j<=maxc;j++)
  {
   if(a1[j]==0)continue;
   t=0;
   while(num%j==0)
   {
    num/=j;
    t++;
   }
   if(!t)
   {
    flag=1;
    break;
   }
   res=max(res,(a1[j]-1)/t);
  }
  if(!flag)ans=min(ans,res);
 }
 if(ans==INF)puts("-1");
 else printf("%d\n",ans+1);
 return 0;
}