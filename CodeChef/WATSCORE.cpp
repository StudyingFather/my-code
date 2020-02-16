#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[15];
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  memset(a,0,sizeof(a));
  int n;
  cin>>n;
  while(n--)
  {
   int p,s;
   cin>>p>>s;
   a[p]=max(a[p],s);
  }
  int ans=0;
  for(int i=1;i<=8;i++)
   ans+=a[i];
  cout<<ans<<endl;
 }
 return 0;
}