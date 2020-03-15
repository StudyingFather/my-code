#include <iostream>
#include <algorithm>
using namespace std;
long long a[100005],b[100005];
int main()
{
 int n;
 long long ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 sort(a+1,a+n+1);
 for(int i=1;i<=n;i++)
  if(i<=(n+1)/2)b[i]=a[2*i-1];
  else b[i]=a[(n-i+1)*2];
 b[n+1]=b[1];
 for(int i=1;i<=n;i++)
  ans+=(b[i+1]-b[i])*(b[i+1]-b[i]);
 cout<<ans<<endl;
 return 0;
}