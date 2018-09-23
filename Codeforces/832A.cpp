#include <iostream>
using namespace std;
int main()
{
 long long n,k,yu;
 cin>>n>>k;
 yu=n%(2*k);
 if(yu>=k)cout<<"YES";
 else cout<<"NO";
 return 0;
} 
