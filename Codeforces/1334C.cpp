#include <iostream>
using namespace std;
long long a[600005],b[600005],d[600005];
int main()
{
 ios::sync_with_stdio(false);
 int t;
 cin>>t;
 while(t--)
 {
  int n;
  long long ans=1e18;
  cin>>n;
  for(int i=1;i<=n;i++)
   cin>>a[i]>>b[i];
  for(int i=n+1;i<=2*n;i++)
   a[i]=a[i-n],b[i]=b[i-n];
  for(int i=1;i<2*n;i++)
   if(b[i]<a[i+1])d[i]=a[i+1]-b[i];
   else d[i]=0;
  for(int i=1;i<2*n;i++)
   d[i]+=d[i-1];
  for(int i=1;i<=n;i++)
   ans=min(ans,a[i]+d[i+n-2]-d[i-1]);
  cout<<ans<<endl;
 }
 return 0;
}