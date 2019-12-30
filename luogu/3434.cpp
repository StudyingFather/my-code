#include <iostream>
#include <algorithm>
using namespace std;
int r[300005],a[300005];
int main()
{
 int n,m;
 cin>>n>>m;
 a[0]=2e9;
 for(int i=1;i<=n;i++)
 {
  cin>>r[i];
  a[i]=min(a[i-1],r[i]);
 }
 int cur=n;
 for(int i=1;i<=m;i++)
 {
  int k;
  cin>>k;
  while(a[cur]<k)
   cur--;
  if(cur&&i!=m)cur--;
 }
 cout<<cur<<endl;
 return 0;
}