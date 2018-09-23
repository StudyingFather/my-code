#include <iostream>
using namespace std;
int a,b,n;
int main()
{
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a>>b;
  if(a<b)cout<<'<'<<endl;
  else if(a==b)cout<<'='<<endl;
  else cout<<'>'<<endl;
 }
 return 0;
}
