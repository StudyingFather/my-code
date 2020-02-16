#include <iostream>
using namespace std;
int main()
{
 int n,a,b,x,y;
 cin>>n>>a>>x>>b>>y;
 a--,x--,b--,y--;
 while(1)
 {
  if(a==b)
  {
   cout<<"YES"<<endl;
   return 0;
  }
  if(a==x||b==y)
  {
   cout<<"NO"<<endl;
   return 0;
  }
  a=(a+1)%n;
  b=(b-1+n)%n;
 }
}