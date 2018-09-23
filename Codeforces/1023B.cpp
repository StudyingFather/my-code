#include <iostream>
using namespace std;
long long n,k;
int main()
{
 cin>>n>>k;
 if(k<=n)cout<<(k-1)/2<<endl;
 else if(k>=2*n)cout<<0<<endl;
 else cout<<(2*n-k+1)/2<<endl; 
 return 0;
}
