#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
 freopen("code.in","r",stdin);
 freopen("code.out","w",stdout);
 int n;
 unsigned long long k;
 cin>>n>>k;
 for(int i=n-1;i>=0;i--)
 {
  unsigned long long tmp=1ull<<i;
  if(k<tmp)cout<<'0';
  else
  {
   cout<<'1';
   k=(tmp<<1)-1-k;
  }
 }
 cout<<endl;
 return 0;
}