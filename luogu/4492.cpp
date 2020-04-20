#include <iostream>
using namespace std;
long long a[2005][2005];
int main()
{
 int n,p;
 cin>>n>>p;
 for(int i=1;i<=n;i++)
 {
  a[i][i]=i;
  for(int j=0;j<i;j++)
   a[i][j]=1;
  for(int j=i+1;j<=n;j++)
   a[i][j]=a[i][j-1]*j%p;
 }
 long long ans=0;
 for(int i=1;i<=n;i++)
 {
  long long res=0;
  for(int s=1;s<=n-i;s++)
   res=(res+(n-s)*s%p*a[n-i-s+1][n-i]%p*a[i][n-s-1]%p)%p;
  ans=(ans+2*res*a[1][i])%p;
 }
 cout<<ans<<endl;
 return 0;
}