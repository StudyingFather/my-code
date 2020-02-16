#include <iostream>
#include <string>
#define N 100000
#define MOD 1000000007
using namespace std;
long long f[100005],inv[100005];
int count1(string s)
{
 int l=s.length(),ans=0;
 for(int i=0;i<l;i++)
  ans+=(s[i]=='1');
 return ans;
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
void init()
{
 f[0]=1;
 for(int i=1;i<=N;i++)
  f[i]=f[i-1]*i%MOD;
 inv[N]=fpow(f[N],MOD-2);
 for(int i=N;i>=1;i--)
  inv[i-1]=inv[i]*i%MOD;
}
long long c(int x,int y)
{
 return f[x]*inv[y]%MOD*inv[x-y]%MOD;
}
int main()
{
 int T;
 cin>>T;
 init();
 while(T--)
 {
  int n;
  long long ans=0;
  cin>>n;
  string s,t;
  cin>>s>>t;
  int cnt1=count1(s),cnt2=count1(t);
  int max1=min(cnt1,n-cnt2)+min(n-cnt1,cnt2),min1=abs(cnt1-cnt2);
  for(int i=max1;i>=min1;i-=2)
   ans=(ans+c(n,i))%MOD;
  cout<<ans<<endl;
 }
 return 0;
}