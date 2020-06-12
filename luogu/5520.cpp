#include <iostream>
using namespace std;
int type,n,m,p;
long long A(int x,int y)
{
 long long ans=1;
 for(int i=x-y+1;i<=x;i++)
  ans=ans*i%p;
 return ans;
}
int main()
{
 cin>>type>>n>>m>>p;
 cout<<A(n-m+1,m)<<endl;
 return 0;
}