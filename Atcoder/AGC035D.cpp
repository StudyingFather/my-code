#include <iostream>
#include <algorithm>
using namespace std;
long long a[25];
long long dfs(int l,int r,int xl,int xr)
{
 if(r-l<=1)return 0;
 long long ans=1e18;
 for(int i=l+1;i<=r-1;i++)
  ans=min(ans,dfs(l,i,xl,xl+xr)+dfs(i,r,xl+xr,xr)+a[i]*(xl+xr));
 return ans;
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 cout<<a[1]+a[n]+dfs(1,n,1,1)<<endl;
 return 0;
}
