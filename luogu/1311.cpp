#include <cstdio>
#include <algorithm>
using namespace std;
int colt[55],last[55],sum[55];
int main()
{
 int n,k,p,tmp=0,ans=0;
 scanf("%d%d%d",&n,&k,&p);
 for(int i=1;i<=n;i++)
 {
  int col,cost;
  scanf("%d%d",&col,&cost);
  if(cost<=p)tmp=i;
  if(tmp>=last[col])sum[col]=colt[col];
  last[col]=i;
  ans+=sum[col];
  colt[col]++;
 }
 printf("%d\n",ans);
 return 0;
}