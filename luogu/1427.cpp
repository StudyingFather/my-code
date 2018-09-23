#include <iostream>
using namespace std;
long long a[105],cnt,num;
int main()
{
 while(cin>>num&&num)
  a[++cnt]=num;
 for(int i=cnt;i>=1;i--)
  cout<<a[i]<<' ';
 return 0;
}
