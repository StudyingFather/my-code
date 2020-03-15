#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
struct seg
{
 int l,r;
}a[100005];
int s[200005];
long long f[100005];
bool cmp(const seg&a,const seg&b)
{
 return a.l<b.l;
}
long long fpow(long long x,long long y)
{
 long long ans=1;
 while(y)
 {
  if(y&1)ans=ans*x%MOD;
  x=x*x%MOD;
  y>>=1;
 }
 return ans;
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i].l>>a[i].r;
  s[a[i].r]++;
 }
 sort(a+1,a+n+1,cmp);
 for(int i=1;i<=2*n;i++)
  s[i]+=s[i-1];
 for(int i=1;i<=n;i++)
  f[i]=(2*f[i-1]+fpow(2,s[a[i].l-1]))%MOD;
 cout<<f[n]<<endl;
 return 0;
}