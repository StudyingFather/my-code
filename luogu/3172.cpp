#include <iostream>
#define MOD 1000000007
using namespace std;
long long f[100005];
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
 int n,k,l,h;
 cin>>n>>k>>l>>h;
 l=l/k+(l%k>0);
 h/=k;
 if(l>h)
 {
  cout<<0<<endl;
  return 0;
 }
 for(int i=1;i<=h-l;i++)
 {
  int x=l,y=h;
  x=x/i+(x%i>0);
  y/=i;
  if(x>y)continue;
  f[i]=(fpow(y-x+1,n)-(y-x+1)+MOD)%MOD;
 }
 for(int i=h-l;i;i--)
  for(int j=i*2;j<=h-l;j+=i)
   f[i]=(f[i]-f[j]+MOD)%MOD;
 cout<<(f[1]+(l==1))%MOD<<endl;
 return 0;
}