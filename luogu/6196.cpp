#include <iostream>
using namespace std;
int a[1000005];
int main()
{
 int n;
 long long ans=0;
 cin>>n;
 a[1]=a[n+2]=1;
 for(int i=2;i<=n+1;i++)
  cin>>a[i];
 int mina=10000;
 for(int i=2;i<=n+1;i++)
 {
  if(a[i]==1)ans++;
  else if(a[i+1]==1)
  {
   ans+=min(mina,a[i]);
   mina=10000;
  }
  else ans+=a[i]*a[i+1],mina=min(mina,a[i]);
 }
 cout<<ans<<endl;
 return 0;
}