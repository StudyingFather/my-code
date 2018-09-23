#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
long long maxd;
long long ans[100005],l[100005];
set<long long> pan;
bool flag;
long long gcd(long long a,long long b)
{
 return b==0?a:gcd(b,a%b);
}
long long get_first(long long a,long long b)
{
 return b/a+1;
}
bool best(long long d)
{
 for(long long i=d;i;i--)
  if(ans[i]!=l[i])
   return ans[i]==-1||l[i]<ans[i];
 return false;
}
void dfs(long long d,long long from,long long a,long long b)
{
 if(d==maxd)
 {
  if(b%a||pan.count(b/a))return;
  l[d]=b;
  if(best(d))memcpy(ans,l,sizeof(long long)*(d+1)); 
  flag=true;
  return;
 }
 from=max(from,get_first(a,b));
 for(long long i=from;;i++)
 {
  if(a*i>=b*(maxd-d+1))return;
  if(pan.count(i))continue;
  l[d]=i;
  long long a1=a*i-b,b1=b*i;
  long long temp=gcd(a1,b1);
  dfs(d+1,i+1,a1/temp,b1/temp);
 }
}
int main()
{
 long long a,b,t,kase=0,k;
 cin>>t;
 while(t--)
 {
  flag=false;
  pan.clear();
  cin>>a>>b>>k;
  for(long long i=1;i<=k;i++)
  {
   long long num;
   cin>>num;
   pan.insert(num);
  }
  for(maxd=1;;maxd++)
  {
   memset(ans,-1,sizeof(ans));
   dfs(0,get_first(a,b),a,b);
   if(flag)
   {
    cout<<"Case "<<++kase<<": "<<a<<'/'<<b<<'=';
    cout<<"1/"<<ans[0];
    for(long long i=1;i<=maxd;i++)
     cout<<"+1/"<<ans[i];
    puts("");
    break;
   }
  }
 }
 return 0;
}
