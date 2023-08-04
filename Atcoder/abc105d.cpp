#include <iostream>
#include <map>
using namespace std;
long long n,m,a[100005],c[100005];
map<long long,long long> mp;
int main()
{
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=1;i<=n;i++)
 {
  c[i]=c[i-1]+a[i];
  c[i]%=m;
  mp[c[i]]++;
 }
 long long ans=mp[0];
 if(mp[0]>1)ans+=mp[0]*(mp[0]-1)/2;
 mp[0]=0;
 for(int i=1;i<=n;i++)
  if(mp[c[i]])
   ans+=mp[c[i]]*(mp[c[i]]-1)/2,mp[c[i]]=0; 
 cout<<ans;
 return 0;
}
