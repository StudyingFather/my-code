#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
long long a[200005],res[200005];
int gcd(int x,int y)
{
 return y==0?x:gcd(y,x%y);
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 sort(a+1,a+n+1);
 while(m--)
 {
  int k;
  cin>>k;
  int p=k!=0?n/gcd(n,k):0;
  if(res[p])cout<<res[p]<<endl;
  else if(k==0)
  {
   for(int i=1;i<=n;i++)
    res[0]+=a[i]*a[i];
   cout<<res[0]<<endl;
  }
  else
  {
   for(int i=1;i<=n;i+=p)
   {
    for(int j=0;j<p-2;j++)
     res[p]+=a[i+j]*a[i+j+2];
    res[p]+=a[i]*a[i+1]+a[i+p-1]*a[i+p-2];
   }
   cout<<res[p]<<endl;
  }
 }
 return 0;
}