#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
 long long s,d;
}a[105];
int main()
{
 int n,t;
 cin>>n>>t;
 for(int i=1;i<=n;i++)
  cin>>a[i].s>>a[i].d;
 for(int i=t;;i++)
  for(int j=1;j<=n;j++)
   if((i-a[j].s)%a[j].d==0&&i>=a[j].s)
   {
    cout<<j<<endl;
    return 0;
   }
 return 0;
}