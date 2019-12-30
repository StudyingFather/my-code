#include <iostream>
#include <algorithm>
#define N 100000
using namespace std;
long long pri[100005],phi[100005];
void init()
{
 phi[1]=1;
 int cnt=0;
 for(int i=2;i<=N;i++)
 {
  if(!phi[i])
  {
   phi[i]=i-1;
   pri[++cnt]=i;
  }
  for(long long j=1;j<=cnt&&i*pri[j]<=N;j++)
  {
   if(i%pri[j]==0)
   {
    phi[i*pri[j]]=phi[i]*pri[j];
    break;
   }
   phi[i*pri[j]]=phi[i]*phi[pri[j]];
  }
 }
 for(int i=1;i<=N;i++)
  phi[i]+=phi[i-1];
}
int main()
{
 long long n,m;
 cin>>n>>m;
 init();
 long long ans=0;
 if(n>m)swap(n,m);
 for(int l=1,r;l<=n;l=r+1)
 {
  r=min(n/(n/l),m/(m/l));
  ans+=(phi[r]-phi[l-1])*(n/l)*(m/l);
 }
 ans=ans*2-n*m;
 cout<<ans<<endl;
 return 0;
}