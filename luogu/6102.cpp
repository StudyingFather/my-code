#include <iostream>
using namespace std;
unsigned t[35];
int main()
{
 ios::sync_with_stdio(false);
 unsigned n,tot,ans=0;
 cin>>n;
 tot=n*n;
 for(int i=1;i<=n;i++)
 {
  unsigned x;
  cin>>x;
  for(int j=0;j<=31;j++)
   if((x>>j)&1)t[j]++;
 }
 for(int i=0;i<=31;i++)
 {
  unsigned andn=t[i]*t[i],orn=(n-t[i])*(n-t[i]);
  ans+=(andn*orn+(tot-andn)*(tot-orn))<<i;
 }
 cout<<ans<<endl;
 return 0;
}