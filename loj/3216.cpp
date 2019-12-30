#include <iostream>
#include <algorithm>
using namespace std;
int n,k,ans=2019;
int f(int x,int y)
{
 if(x/2<y)y=x+1-y;
 return (x-y+1)*y;
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>k;
 for(int i=1;i<=n;i++)
  for(int j=1;j<=i;j++)
  {
   int num;
   cin>>num;
   if(f(i,j)<=k)ans=min(ans,num);
  }
 cout<<ans<<endl;
 return 0;
}