#include <iostream>
#include <cmath>
using namespace std;
long long pow_2[65],maxc;
void div_2(long long a)
{
 if(a)
 {
  maxc++;
  div_2(a/2);
 }
}
void get_pow_2()
{
 pow_2[1]=1;
 for(int i=2;i<=maxc;i++)
  pow_2[i]=pow_2[i-1]*2;
}
int main()
{
 long long n,k,ans=0;
 cin>>n>>k;
 div_2(n);
 get_pow_2();
 if(k>=2)
  for(int i=maxc;i;i--)
   ans+=pow_2[i];
 else ans=n;
 cout<<ans;
 return 0;
}
