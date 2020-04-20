#include <iostream>
using namespace std;
int a[300005],b[300005],n;
int main()
{
 int ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=1;i<=n;i++)
  if(b[a[i]]==i-1)b[a[i]]=i;
 for(int i=1;i<=n;i++)
  ans=max(ans,i-b[a[i]]-1);
 cout<<ans<<endl;
 return 0;
}