#include <cstdio>
#include <iostream>
using namespace std;
long long n,q;
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>q;
 for(int i=1;i<=q;i++)
 {
  long long x,y;
  cin>>x>>y;
  if(x%2==y%2)
  {
   if(n%2)cout<<((x-1)*n+1)/2+(y+1)/2<<endl;
   else cout<<(x-1)*n/2+(y+1)/2<<endl;
  }
  else
  {
   if(n%2)cout<<((x-1)*n+1)/2+y/2+(n*n+1)/2<<endl;
   else cout<<(x-1)*n/2+(y+1)/2+n*n/2<<endl;
  }
 }
 return 0;
}
