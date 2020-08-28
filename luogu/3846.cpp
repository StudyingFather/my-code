// Problem : P3846 [TJOI2007] 可爱的质数/【模板】BSGS
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/P3846
// Memory Limit : 125 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<long long,int> s;
long long a,b,p;
long long fpow(long long x,long long y)
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
int main()
{
 cin>>p>>a>>b;
 int sp=ceil(sqrt(p));
 long long tmp=b;
 for(int i=0;i<=sp;i++)
 {
  s[tmp]=i;
  tmp=tmp*a%p;
 }
 tmp=fpow(a,sp);
 long long num=1;
 int ans=p;
 for(int i=0;i<=sp;i++)
 {
  if(s.count(num))
   if(i*sp-s[num]>=0)
    ans=min(ans,i*sp-s[num]);
  num=num*tmp%p;
 }
 if(ans==p)cout<<"no solution"<<endl;
 else cout<<ans<<endl;
 return 0;
}