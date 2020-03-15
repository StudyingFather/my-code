#include <iostream>
#include <algorithm>
#include <unordered_map>
#define N 20000000
using namespace std;
typedef unsigned long long ull;
ull phi[N+5];
int pri[N+5],cnt;
bool vis[N+5];
unordered_map<ull,ull> psum;
ull fpow(ull x,ull y)
{
 ull ans=1;
 while(y)
 {
  if(y&1)ans=ans*x;
  x=x*x;
  y>>=1;
 }
 return ans;
}
ull phi_sum(ull x)
{
 if(x<=N)return phi[x];
 if(psum.count(x))return psum[x];
 ull res=(x&1)?(x+1)/2*x:x/2*(x+1);
 for(ull l=2,r;l<=x;l=r+1)
 {
  r=x/(x/l);
  res-=(r-l+1)*phi_sum(x/l);
 }
 return psum[x]=res;
}
int main()
{
 ull n,m,ans=0;
 cin>>n>>m;
 phi[1]=1;
 for(int i=2;i<=N;i++)
 {
  if(!vis[i])phi[i]=i-1,pri[++cnt]=i;
  for(int j=1;j<=cnt&&i*pri[j]<=N;j++)
  {
   vis[i*pri[j]]=1;
   if(i%pri[j]!=0)
    phi[i*pri[j]]=phi[i]*phi[pri[j]];
   else
   {
    phi[i*pri[j]]=phi[i]*pri[j];
    break;
   }
  }
 }
 for(int i=1;i<=N;i++)
  phi[i]+=phi[i-1];
 for(ull l=1,r;l<=m;l=r+1)
 {
  r=m/(m/l);
  ans+=fpow(m/l,n)*(phi_sum(r)-phi_sum(l-1));
 }
 cout<<ans<<endl;
 return 0;
}