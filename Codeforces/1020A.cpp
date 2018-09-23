#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
 long long n,h,a,b,k;
 cin>>n>>h>>a>>b>>k;
 for(int i=1;i<=k;i++)
 {
  long long ta,fa,tb,fb;
  cin>>ta>>fa>>tb>>fb;
  if(ta==tb)cout<<abs(fa-fb)<<endl;
  else
  {
   if(a<=fa&&fa<=b)cout<<abs(fa-fb)+abs(ta-tb)<<endl;
   else if(a>fa)cout<<a-fa+abs(ta-tb)+abs(a-fb)<<endl;
   else cout<<fa-b+abs(ta-tb)+abs(b-fb)<<endl;
  }
 }
 return 0;
}
