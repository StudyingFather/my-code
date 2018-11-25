#include <iostream>
#include <algorithm>
using namespace std;
struct song
{
 int a,b,diff;
}a[100005];
long long n,m,sum;
bool cmp(const song&a,const song&b)
{
 return a.diff>b.diff;
}
int main()
{
 cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i].a>>a[i].b;
  a[i].diff=a[i].a-a[i].b;
  sum+=a[i].a;
 }
 sort(a+1,a+n+1,cmp);
 if(sum<=m)
 {
  cout<<0<<endl;
  return 0;
 }
 for(int i=1;i<=n;i++)
 {
  sum-=a[i].diff;
  if(sum<=m)
  {
   cout<<i<<endl;
   return 0;
  }
 }
 cout<<-1;
 return 0;
}
