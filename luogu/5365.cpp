#include <iostream>
#include <algorithm>
using namespace std;
long long f[2000005];
int k[505],c[505];
int main()
{
 long long n,m;
 cin>>n>>m;
 f[0]=1;
 for(int i=1;i<=n;i++)
  cin>>k[i];
 for(int i=1;i<=n;i++)
  cin>>c[i];
 int maxv=0;
 for(int i=1;i<=n;i++)
  maxv+=k[i]*c[i];
 for(int i=1;i<=n;i++)
  for(int j=maxv;j;j--)
   for(int p=1;p<=k[i]&&p*c[i]<=j;p++)
    f[j]=max(f[j],f[j-p*c[i]]*p);
 for(int i=1;;i++)
  if(f[i]>=m)
  {
   cout<<i<<endl;
   return 0;
  }
}