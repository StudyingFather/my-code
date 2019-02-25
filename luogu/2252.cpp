#include <iostream>
#include <cmath>
using namespace std;
int main()
{
 long long x,y;
 cin>>x>>y;
 if(x>y)swap(x,y);
 int res=(y-x)*(sqrt(5)+1)/2;
 if(res==x)cout<<0<<endl;
 else cout<<1<<endl;
 return 0;
}