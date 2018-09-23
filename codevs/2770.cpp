#include <iostream>
using namespace std;
int main()
{
 int k,n,a;
 cin>>n>>k;
 a=(n-k*(k-1)/2)/k;
 for(int i=0;i<k;i++)
  cout<<a+i<<" ";
 return 0;
}
