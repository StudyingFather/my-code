#include <iostream>
using namespace std;
long long phi[40005],n,ans;
int main()
{
 cin>>n;
 if(n==1)
 {
  cout<<0<<endl;
  return 0;
 }
 for(int i=1;i<=n;i++)
  phi[i]=i;
 for(int i=2;i<=n;i++)
  if(phi[i]==i)
  {
   for(int j=1;i*j<=n;j++)
    phi[i*j]=phi[i*j]/i*(i-1);
  }
 for(int i=2;i<n;i++)
  ans+=phi[i]*2;
 cout<<ans+3<<endl;
 return 0;
}
