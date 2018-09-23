#include <iostream>
using namespace std;
int n,vis[105];
long long a[105],ans[105];
void dfs(int d)
{
 if(d==n+1)
 {
  for(int i=1;i<=n;i++)
   cout<<ans[i]<<' ';
  return;
 }
 for(int i=1;i<=n;i++)
 {
  if(!vis[i])
  {
   if(d==1)
   {
   	vis[i]=1;
   	ans[d]=a[i];
   	dfs(d+1);
   	vis[i]=0;
   	ans[d]=0;
   }
   else if(3*a[i]==ans[d-1]||a[i]==2*ans[d-1])
   {
   	vis[i]=1;
   	ans[d]=a[i];
   	dfs(d+1);
   	vis[i]=0;
   	ans[d]=0;
   }
  }
 }
}
int main()
{
 cin>>n;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 dfs(1);
 return 0;
}
