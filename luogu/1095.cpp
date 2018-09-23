#include <algorithm>
#include <cstdio> 
using namespace std;
int m,s,t,MaxDist;
struct DP
{
 int f,g,m;
}dp[300005];
int main()
{
 scanf("%d%d%d",&m,&s,&t);
 dp[0].f=dp[0].g=0;
 dp[0].m=m;
 for(int i=1;i<=t;i++)
 {
  if(dp[i-1].m>=10)
  {
   dp[i].m=dp[i-1].m-10;
   dp[i].g=dp[i-1].g+60;
  }
  else
  {
   dp[i].m=dp[i-1].m+4;
   dp[i].g=dp[i-1].g;
  }
  dp[i].f=max(dp[i-1].f+17,dp[i].g);
 }
 if(dp[t].f<s)printf("No\n%d",dp[t].f);
 else 
 {
  while(dp[t].f>=s)
   t--;
  printf("Yes\n%d",++t);
 }
 return 0;
}
