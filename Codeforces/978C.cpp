#include <iostream>
using namespace std;
long long n,m,a[200005],b[200005],c[200005];
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  c[i]=c[i-1]+a[i];
 }
 int f=1;
 for(int i=1;i<=m;i++)
 {
  cin>>b[i];
  long long k=b[i]-c[f-1];
  while(k>a[f])
   k-=a[f++];
  cout<<f<<' '<<k<<endl;
 }
 return 0;
}
