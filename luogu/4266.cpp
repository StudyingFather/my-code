#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct reststop
{
 long long x,c;
}a[100005];
bool cmp(const reststop&a,const reststop&b)
{
 return a.c>b.c||(a.c==b.c&&a.x>b.x);
}
long long maxc[100005],s;
long long ans;
int main()
{
 int l,n,rf,rb;
 cin>>l>>n>>rf>>rb;
 for(int i=1;i<=n;i++)
  cin>>a[i].x>>a[i].c;
 sort(a+1,a+n+1,cmp);
 for(int i=1;i<=n;i++)
  if(s<a[i].x)
  {
   ans+=(a[i].x-s)*(rf-rb)*a[i].c;
   s=a[i].x;
  }
 cout<<ans;
 return 0;
}