#include <iostream>
using namespace std;
int f(int x)
{
 int ans=(x%10==5?-1:0);
 while(x)
  x/=10,ans+=2;
 return ans;
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  long long l,r,s=1,t=1e9,x;
  cin>>l>>r;
  while(l<=r)
  {
   while(l%(s*10)==0)s*=10;
   if(t>f(l/s))
   {
    x=l;
    t=f(l/s);
   }
   l+=s;
  }
  cout<<x<<endl;
 }
 return 0;
}