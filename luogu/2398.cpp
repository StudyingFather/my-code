#include <iostream>
using namespace std;
int pri[100005],phi[100005],tot;
long long sum[100005];
int main()
{
 int n;
 cin>>n;
 phi[1]=1;
 for(int i=2;i<=n;i++)
 {
  if(!phi[i])pri[++tot]=i,phi[i]=i-1;
  for(int j=1;j<=tot&&i*pri[j]<=n;j++)
   if(i%pri[j]==0)
   {
    phi[i*pri[j]]=phi[i]*pri[j];
    break;
   }
   else phi[i*pri[j]]=phi[i]*phi[pri[j]];
 }
 for(int i=1;i<=n;i++)
  sum[i]=sum[i-1]+phi[i];
 long long ans=0;
 for(int i=1;i<=n;i++)
  ans+=i*(2*sum[n/i]-1);
 cout<<ans<<endl;
 return 0;
}