#include <cstdio>
#include <algorithm>
using namespace std;
int m,k,p[1000005],sum[1000005],cha[1000005],rm; 
int main()
{
 scanf("%d%d",&m,&k);
 rm=k;
 for(int i=1;i<=m;i++)
 {
  scanf("%d",&p[i]);
  sum[i]=sum[i-1]+p[i];
 }
 int ave=sum[m]/k;
 cha[1]=p[1]-ave;
 int start=1;
 for(int i=2;i<=m;i++)
 {
  ave=sum[m]/rm;
  cha[i]=sum[i]-ave*(k-rm+1);
  if(cha[i]>=0)
  {
   printf("%d %d\n",start,max(start,i-1));
   start=i;
   rm--;
  }
  else if(m-i<rm)
  {
   printf("%d %d\n",start,max(start,i));
   start=i+1;
   rm--;
  }
 }
 return 0;
}
