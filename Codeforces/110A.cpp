#include <iostream>
using namespace std;
int main()
{
 long long n;
 cin>>n;
 int ws=0;
 while(n)
 {
  int m=n%10;
  if(m==7||m==4)ws++;
  n/=10;
 }
 if(ws!=7&&ws!=4)cout<<"NO";
 else cout<<"YES";
 return 0;
}
