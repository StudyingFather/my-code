#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int mark[100005],val,num[100005],l[100005],r[100005],maxsum[100005][25],re;
void RMQ()
{
 for(int i=1;i<=re;++i)
  maxsum[i][0]=num[i];
 for(int j=1;(1<<j)<=re+1;++j)
  for(int i=1;i+(1<<j)-1<=re;++i)
   maxsum[i][j]=max(maxsum[i][j-1],maxsum[i+(1<<(j-1))][j-1]);
}
int Max(int a,int b,int c)
{
 if(a<b)a=b;
 if(a<c)a=c;
 return a;
}
int main()
{
 int n,q,k,L,R;
 while(~scanf("%d",&n)&&n)
 {
  re=1;
  scanf("%d%d",&q,&k);
  val=k;
  num[1]=1;
  mark[1]=1;
  l[0]=1;
  for(int i=2;i<=n;i++)
  {
   scanf("%d",&k);
   if(k==val)
   {
    num[re]++;
    mark[i]=re;
   }
   else
   {
    r[re]=i-1;
    re++;
    mark[i]=re;
    l[re]=i;
    val=k;
    num[re]=1;
   }
  }
  RMQ();
  while(q--)
  {
   scanf("%d%d",&L,&R);
   if(mark[L]==mark[R])printf("%d\n",R-L+1);
   else
   {
    int ans=0;
    if(mark[L]+1<=mark[R]-1)
    {
     int k=(int)((log(mark[R]-mark[L]-1))/log(2.0));
     ans=max(maxsum[mark[L]+1][k],maxsum[mark[R]-(1<<k)][k]);
    }
    ans=Max(r[mark[L]]-L+1,ans,R-l[mark[R]]+1);
    printf("%d\n",ans);
   }
  }
 }
 return 0;
}
