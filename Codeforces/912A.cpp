#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
 long long a,b,x,y,z,needa,needb;
 cin>>a>>b>>x>>y>>z;
 needa=max(x*2+y-a,(long long)0);
 needb=max(y+z*3-b,(long long)0);
 cout<<needa+needb;
 return 0;
}
