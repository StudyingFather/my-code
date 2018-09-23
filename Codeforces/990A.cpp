#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
 long long n,m,a,b;
 cin>>n>>m>>a>>b;
 cout<<min(n%m*b,(m-n%m)*a);
 return 0;
}
