#include <cstring>
#include <iostream>
using namespace std;
int a[100005],t[100005];
int main()
{
 int T;
 cin>>T;
 while(T--)
 {
  memset(t,0,sizeof(t));
  int n,k,ans=0,cnt=0;
  cin>>n>>k;
  for(int i=1;i<=n;i++)
   cin>>a[i];
  int l=1,r=0;
  while(l<=n&&r<n)
  {
   while(r<n&&cnt<k)
   {
    r++;
    if(!t[a[r]])cnt++;
    t[a[r]]++;
    if(cnt!=k)ans=max(r-l+1,ans);
   }
   while(cnt==k)
   {
    t[a[l]]--;
    if(!t[a[l]])cnt--;
    l++;
   }
  }
  cout<<ans<<endl;
 }
 return 0;
}