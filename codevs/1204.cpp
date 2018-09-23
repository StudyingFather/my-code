#include <iostream>
#include <cstring>
using namespace std;
char a[105],b[105];
int main()
{
 cin>>a>>b;
 cout<<strstr(a,b)-a+1;
 return 0;
}
