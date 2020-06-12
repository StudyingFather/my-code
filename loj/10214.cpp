#include <cmath>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
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
long long bsgs(int y,int z,int p)
{
 unordered_map<int,long long> s;
 int sqp=sqrt(p);
 long long res=z%p,tmp=fpow(y,sqp,p);
 s[z]=0;
 if(y==0&&z==0)return 1;
 if(y==0&&z)return -1;
 for(int i=1;i*i<=p;i++)
 {
  res=res*y%p;
  s[res]=i;
 }
 res=1;
 for(int i=1;i*i<=p+1;i++)
 {
  res=res*tmp%p;
  if(s[res])return ((i*sqp-s[res])%p+p)%p;
 }
 return -1;
}
int main()
{
 int t,k;
 cin>>t>>k;
 while(t--)
 {
  int y,z,p;
  cin>>y>>z>>p;
  if(k==1)cout<<fpow(y,z,p)<<endl;
  else if(k==2)
  {
   y%=p,z%=p;
   if(y==0&&z!=0)cout<<"Orz, I cannot find x!"<<endl;
   else cout<<z*fpow(y,p-2,p)%p<<endl;
  }
  else
  {
   y%=p;
   long long ans=bsgs(y,z,p);
   if(ans==-1)cout<<"Orz, I cannot find x!"<<endl;
   else cout<<ans<<endl;
  }
 }
 return 0;
}