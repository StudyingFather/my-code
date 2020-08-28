// Problem : P6091 【模板】原根
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P6091
// Memory Limit : 250 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 1000000
int rt[N+5],phi[N+5],pri[N+5],cnt;
int res[N+5];
void init()
{
 rt[2]=rt[4]=1;
 phi[1]=1;
 for(int i=2;i<=N;i++)
 {
  if(!phi[i])
   phi[i]=i-1,pri[++cnt]=i;
  for(int j=1;j<=cnt&&i*pri[j]<=N;j++)
  {
   if(i%pri[j]==0)
   {
    phi[i*pri[j]]=phi[i]*pri[j];
    break;
   }
   phi[i*pri[j]]=phi[i]*phi[pri[j]];
  }
 }
 for(int i=2;i<=cnt;i++)
  for(long long j=pri[i];j<=N;j*=pri[i])
   rt[j]=1;
 for(int i=2;i<=cnt;i++)
  for(long long j=pri[i]*2;j<=N;j*=pri[i])
   rt[j]=1;
}
long long fpow(long long x,long long y,long long p)
{
 long long ans=1;
 while(y)
 {
  if(y&1)ans=ans*x%p;
  x=x*x%p;
  y>>=1;
 }
 return ans;
}
long long gcd(long long x,long long y)
{
 return y==0?x:gcd(y,x%y);
}
int findrt(int x)
{
 vector<int> vec;
 int cx=phi[x];
 for(int i=2;cx!=1;i++)
 {
  if(cx%i==0)
  {
   vec.push_back(i);
   while(cx%i==0)
    cx/=i;
  }
 }
 for(int i=1;;i++)
 {
  bool flag=true;
  if(fpow(i,phi[x],x)!=1)continue;
  for(auto p:vec)
   if(fpow(i,phi[x]/p,x)==1)
   {
    flag=false;
    break;
   }
  if(flag)return i;
 }
}
int main()
{
 int t;
 cin>>t;
 init();
 while(t--)
 {
  int x,d;
  cin>>x>>d;
  if(!rt[x])
   cout<<0<<endl;
  else
  {
   int ans=0;
   long long minrt=findrt(x),crt=minrt;
   for(int i=1;i<=phi[x];i++,crt=crt*minrt%x)
    if(gcd(i,phi[x])==1)
     res[++ans]=crt;
   sort(res+1,res+ans+1);
   cout<<ans<<endl;
   for(int i=d;i<=ans;i+=d)
    cout<<res[i]<<' ';
  }
  cout<<endl;
 }
 return 0;
}