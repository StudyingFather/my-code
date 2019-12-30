#include <iostream>
#define MAXN 40000005
#define MOD 1073741824
using namespace std;
long long s[MAXN];
int n,op,a[MAXN],b[MAXN],p[MAXN],q[MAXN];
void geninput()
{
 if(!op)
 {
  for(int i=1;i<=n;i++)
   cin>>a[i];
 }
 else
 {
  long long x,y,z,m;
  cin>>x>>y>>z>>b[1]>>b[2]>>m;
  for(int i=3;i<=n;i++)
   b[i]=(x*b[i-1]+y*b[i-2]+z)%MOD;
  int lp=0;
  while(m--)
  {
   int p,l,r;
   cin>>p>>l>>r;
   for(int i=lp+1;i<=p;i++)
    a[i]=(b[i]%(r-l+1))+l;
   lp=p;
  }
 }
}
long long f(int x)
{
 return 2*s[x]-s[p[x]];
}
void print(__int128 x)
{
 if(x<10)cout<<(int)x;
 else
 {
  print(x/10);
  cout<<int(x%10);
 }
}
int main()
{
 freopen("partition.in","r",stdin);
 freopen("partition.out","w",stdout);
 ios::sync_with_stdio(false);
 cin>>n>>op;
 geninput();
 for(int i=1;i<=n;i++)
  s[i]=s[i-1]+a[i];
 int l=0,r=0;
 for(int i=1;i<=n;i++)
 {
  while(l<r&&f(q[l+1])<=s[i])
   l++;
  p[i]=q[l];
  while(l<=r&&f(q[r])>=f(i))
   r--;
  q[++r]=i;
 }
 __int128 ans=0;
 for(int i=n;i;i=p[i])
  ans+=(__int128)(s[i]-s[p[i]])*(s[i]-s[p[i]]);
 print(ans);
 return 0;
}