#include <iostream>
#include <algorithm>
using namespace std;
int a[100005],b[100005];
int main()
{
 int A,B,M;
 int ans,mina=1e9,minb=1e9;
 cin>>A>>B>>M;
 for(int i=1;i<=A;i++)
 {
  cin>>a[i];
  mina=min(mina,a[i]);
 }
 for(int i=1;i<=B;i++)
 {
  cin>>b[i];
  minb=min(minb,b[i]);
 }
 ans=mina+minb;
 for(int i=1;i<=M;i++)
 {
  int x,y,c;
  cin>>x>>y>>c;
  ans=min(ans,a[x]+b[y]-c);
 }
 cout<<ans<<endl;
 return 0;
}