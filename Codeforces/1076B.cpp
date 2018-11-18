#include <iostream>
using namespace std;
int main()
{
 long long n;
 cin>>n;
 for(long long i=2;i*i<=n;i++)
  if(n%i==0)
  {
   cout<<n/i<<endl;
   return 0;
  }
 cout<<1<<endl;
 return 0;
}
