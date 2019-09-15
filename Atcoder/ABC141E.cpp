#include <cstdio>
#include <set>
#define MOD 1000000007
#define MOD2 998244353
using namespace std;
char s[5005];
int n;
bool check(int len)
{
 set<long long> se,se2;
 for(int i=1;i+len-1<=n;i++)
 {
  long long sum=0,sum2=0;
  if(i-len>0)//每次插入当前串前面的一个长度为 len 的串，确保不重叠
  {
   for(int j=i-len;j<i;j++)
    sum=(sum*26+s[j]-'a')%MOD,sum2=(sum2*26+s[j]-'a')%MOD2;
   se.insert(sum),se2.insert(sum2);
  }
  sum=0,sum2=0;
  for(int j=i;j<=i+len-1;j++)
   sum=(sum*26+s[j]-'a')%MOD,sum2=(sum2*26+s[j]-'a')%MOD2;
  if(se.count(sum)&&se2.count(sum2))return true;
 }
 return false;
}
int main()
{
 scanf("%d",&n);
 scanf("%s",s+1);
 int l=0,r=n/2;
 while(l<r)
 {
  int mid=(l+r+1)>>1;
  if(check(mid))l=mid;
  else r=mid-1;
 }
 printf("%d\n",l);
 return 0;
}