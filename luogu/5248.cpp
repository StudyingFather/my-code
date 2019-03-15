#include <iostream>
using namespace std;
long long n,ans[100005];
int main()
{
 long long m,fm;
 cin>>m>>fm;
 while(fm)
 {
  ans[++n]=fm%m;
  fm/=m;
 }
 cout<<n<<endl;
 for(int i=1;i<=n;i++)
  cout<<ans[i]<<' ';
 return 0;
}