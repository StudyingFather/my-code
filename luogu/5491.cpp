// Problem: P5491 【模板】二次剩余
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5491
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
struct comp
{
 long long x,y;
};
long long w;
comp mul(comp x,comp y,long long p)
{
 comp ans={0,0};
 ans.x=(x.x*y.x%p+x.y*y.y%p*w%p)%p;
 ans.y=(x.x*y.y+y.x*x.y)%p;
 return ans;
}
long long fpowr(long long x,long long y,long long p)
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
long long fpowi(comp x,long long y,long long p)
{
 comp ans={1,0};
 while(y)
 {
  if(y&1)ans=mul(ans,x,p);
  x=mul(x,x,p);
  y>>=1;
 }
 return ans.x;
}
long long cipolla(long long n,long long p)
{
 n%=p;
 if(fpowr(n,(p-1)/2,p)==p-1)return -1;
 long long a;
 while(1)
 {
  a=rand()%p,w=(a*a%p-n+p)%p;
  if(fpowr(w,(p-1)/2,p)==p-1)break;
 }
 return fpowi({a,1},(p+1)/2,p);
}
int main()
{
 srand(time(NULL));
 int t;
 cin>>t;
 while(t--)
 {
  long long n,p;
  cin>>n>>p;
  if(n==0)
  {
   cout<<0<<endl;
   continue;
  }
  long long ans1=cipolla(n,p),ans2;
  if(ans1==-1)
   cout<<"Hola!"<<endl;
  else
  {
   ans2=p-ans1;
   if(ans1>ans2)swap(ans1,ans2);
   if(ans1==ans2)cout<<ans1<<endl;
   else cout<<ans1<<' '<<ans2<<endl;
  }
 }
 return 0;
}