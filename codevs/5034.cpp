#include <iostream>
#include <algorithm>
using namespace std;
long long a[50005],n;
int main()
{
 cin>>n;
 for(int i=0;i<n;i++)
  cin>>a[i];
 sort(a,a+n);
 for(int i=0;i<n;i++)
  cout<<a[i]<<' ';
 return 0;
}
