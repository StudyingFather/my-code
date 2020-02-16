#include <iostream>
#define MOD 10000000000ll
using namespace std;
long long fpow(int x,int y)
{
 long long ans=1;
 while(y--)
  ans=ans*x%MOD;
 return ans;
}
int main()
{
 cout<<(28433*fpow(2,7830457)+1)%MOD<<endl;
 return 0;
}