// Problem: #167. 康托展开
// Contest: LibreOJ
// URL: https://loj.ac/problem/167
// Memory Limit: 16 MB
// Time Limit: 200 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#define MOD 998244353
using namespace std;
long long f[1000005];
struct BIT
{
 int a[1000005],n;
 void init(int n)
 {
  this->n=n;
 }
 int lowbit(int x)
 {
  return x&(-x);
 }
 void add(int x,int y)
 {
  while(x<=n)
  {
   a[x]+=y;
   x+=lowbit(x);
  }
 }
 int query(int x)
 {
  int ans=0;
  while(x)
  {
   ans+=a[x];
   x-=lowbit(x);
  }
  return ans;
 }
}tr;
int main()
{
 ios::sync_with_stdio(false);
 int n;
 long long ans=0;
 cin>>n;
 f[0]=1;
 tr.init(n);
 for(int i=1;i<=n;i++)
  f[i]=f[i-1]*i%MOD;
 for(int i=1;i<=n;i++)
 {
  int x;
  cin>>x;
  ans=(ans+(x-tr.query(x)-1)*f[n-i])%MOD;
  tr.add(x,1);
 }
 cout<<(ans+1)%MOD<<endl;
 return 0;
}