#include <iostream>
using namespace std;
unsigned long long a[200005],b[200005];
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n/2;i++)
  cin>>b[i];
 a[1]=0,a[n]=b[1];
 for(int i=2;i<=n/2;i++)
  if(b[i]-a[i-1]<=a[n-i+2])
  {
   a[i]=a[i-1];
   a[n-i+1]=b[i]-a[i];
  }
  else
  {
   a[n-i+1]=a[n-i+2];
   a[i]=b[i]-a[n-i+1];
  }
 for(int i=1;i<=n;i++)
  cout<<a[i]<<' ';
 return 0;
}
