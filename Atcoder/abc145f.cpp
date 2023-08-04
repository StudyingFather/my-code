#include <cstring>
#include <iostream>
using namespace std;
long long f[305][305];
int h[305];
int main()
{
 int n,k;
 long long ans=1e18;
 cin>>n>>k;
 for(int i=1;i<=n;i++)
  cin>>h[i];
 memset(f,63,sizeof(f));
 if(n==k)
 {
  cout<<0<<endl;
  return 0;
 }
 for(int i=n;i;i--)
 {
  f[i][1]=h[i];
  for(int j=2;j<=n-k;j++)
   for(int p=i-1;p;p--)
    f[p][j]=min(f[p][j],f[i][j-1]+max(0,h[p]-h[i]));
 }
 for(int i=1;i<=n;i++)
  ans=min(ans,f[i][n-k]);
 cout<<ans<<endl;
 return 0;
}