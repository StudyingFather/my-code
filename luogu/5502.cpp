#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
long long a[100005];
queue<int> p,q;
long long gcd(long long x,long long y)
{
 return y==0?x:gcd(y,x%y);
}
int main()
{
 int n;
 long long ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  int l=0;
  while(!q.empty())
  {
   int u=q.front();
   q.pop();
   a[u]=gcd(a[u],a[i]);
   ans=max(ans,a[u]*(i-u+1));
   if(a[u]!=a[l])
   {
    p.push(u);
    l=u;
   }
  }
  ans=max(ans,a[i]);
  while(!p.empty())
  {
   q.push(p.front());
   p.pop();
  }
  if(a[i]!=a[l])q.push(i);
 }
 cout<<ans<<endl;
 return 0;
}