#include <iostream>
#include <algorithm>
using namespace std;
int a[20],n;
int main()
{
 cin>>n;
 for(int i=0;i<n;i++)
  cin>>a[i];
 sort(a+0,a+n);
 for(int i=0;i<n;i++)
  cout<<a[i]<<endl;
 return 0;
}
