#include <iostream>
#include <algorithm>
using namespace std;
long long my_pow(int x)
{
 long long ans=1;
 for(int i=1;i<=x;i++)
  ans*=10;
 return ans;
}
int main()
{
 long long n,ans=0,cnt=0,n1;
 cin>>n;
 n1=n;
 while(n1>0)
 {
  n1/=10;
  ans++;
 }
 ans--;
 for(int i=0;i<ans;i++)
  n-=9*my_pow(i);
 if(n==0)ans++;
 ans*=9;
 while(n>0)
 {
  ans+=n%10;
  n/=10;
 }
 cout<<ans;
 return 0;
}