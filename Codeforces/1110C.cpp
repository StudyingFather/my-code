#include <cmath>
#include <iostream>
using namespace std;
int f(int x)
{
 int ans=0;
 while(x)
 {
  x>>=1;
  ans++;
 }
 return ans;
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int x;
  cin>>x;
  if(x&(x+1))cout<<(1<<f(x))-1<<endl;
  else
  {
   bool flag=true;
   for(int i=2;i*i<=x;i++)
    if(x%i==0)
    {
     cout<<x/i<<endl;
     flag=false;
     break;
    }
   if(flag)cout<<1<<endl;
  }
 }
 return 0;
}