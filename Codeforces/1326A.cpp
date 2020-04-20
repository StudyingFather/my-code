#include <iostream>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n;
  cin>>n;
  if(n==1)cout<<-1<<endl;
  else
  {
   cout<<2;
   for(int i=2;i<=n;i++)
    cout<<3;
   cout<<endl;
  }
 }
 return 0;
}