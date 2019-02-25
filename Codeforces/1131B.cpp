#include <iostream>
#include <algorithm>
using namespace std;
long long calc(int a,int b,int lasta,int lastb)
{
 if(a>b)swap(a,b);
 if(lasta>lastb)swap(lasta,lastb);
 if(lasta<b)return 0;
 return lasta-b+1-(a==b);
}
int main()
{
 long long n,a=0,b=0,lasta,lastb,ans=1;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>lasta>>lastb;
  if(a!=lasta||b!=lastb)ans+=calc(a,b,lasta,lastb);
  a=lasta,b=lastb;
 }
 cout<<ans<<endl;
 return 0;
}