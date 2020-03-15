#include <iostream>
using namespace std;
char s[505];
bool a[505];
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,k,ans=0;
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
   cin>>(s+i);
   a[i]=(s[i]=='H');
  }
  bool op=false;
  for(int i=n;n-i+1<=k;i--)
   if(a[i]^op)op^=1;
  for(int i=1;i<=n-k;i++)
   ans+=a[i]^op;
  cout<<ans<<endl;
 }
 return 0;
}