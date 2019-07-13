#include <iostream>
using namespace std;
void exgcd(long long a,long long b,long long&x,long long&y)
{
 if(!b)
 {
  x=1,y=0;
  return;
 }
 exgcd(b,a%b,x,y);
 int tmp=x;
 x=y;
 y=tmp-a/b*y;
}
long long gcd(long long x,long long y)
{
 return y==0?x:gcd(y,x%y);
}
int main()
{
 long long x,y,m,n,l,p,q;
 cin>>x>>y>>m>>n>>l;
 long long a=n-m,b=x-y,gcdnum,mod;
 if(a<0)a=-a,b=-b;
 gcdnum=gcd(a,l),mod=abs(l/gcdnum);
 exgcd(a,l,p,q);
 if(b%gcdnum)cout<<"Impossible"<<endl;
 else cout<<(p*b/gcdnum%mod+mod)%mod<<endl;
 return 0;
}