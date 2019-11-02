/*
 Name: luogu P4370
 Author: StudyingFather
 Date: 2019/10/20 01:19
 Website: https://studyingfather.com
*/
#include <cmath>
#include <iostream>
#include <queue>
#define MOD 1000000007
using namespace std;
struct node
{
 int x,y;
 double v;
 bool operator<(const node&a)const
 {
  return v<a.v;
 }
};
priority_queue<node> q;
double sum[1000005];
long long f[1000005],inv[1000005];
long long fpow(long long x,int y)
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
double c1(int x,int y)
{
 return sum[x]-sum[y]-sum[x-y];
}
long long c2(int x,int y)
{
 return f[x]*inv[y]%MOD*inv[x-y]%MOD;
}
int main()
{
 int n,k;
 cin>>n>>k;
 f[0]=inv[0]=1;
 for(int i=1;i<=n;i++)
  f[i]=f[i-1]*i%MOD;
 inv[n]=fpow(f[n],MOD-2);
 for(int i=n;i>1;i--)
  inv[i-1]=inv[i]*i%MOD;
 for(int i=1;i<=n;i++)
  sum[i]=sum[i-1]+log(i);
 for(int i=0;i<=n;i++)
  q.push({n,i,c1(n,i)});
 long long ans=0;
 for(int i=1;i<=k;i++)
 {
  int x=q.top().x,y=q.top().y;
  q.pop();
  ans=(ans+c2(x,y))%MOD;
  if(x>y)q.push({x-1,y,c1(x-1,y)});
 }
 cout<<ans<<endl;
 return 0;
}