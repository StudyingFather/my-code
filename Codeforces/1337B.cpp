#include <iostream>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int x,n,m;
  cin>>x>>n>>m;
  while(n)
  {
   int nx=x/2+10;
   if(x>nx)x=nx,n--;
   else break;
  }
  while(m)
   x-=10,m--;
  if(x>0)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
 }
 return 0;
}