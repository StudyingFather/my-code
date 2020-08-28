// Problem: P5598 【XR-4】混乱度
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5598
// Memory Limit: 500 MB
// Time Limit: 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
long long a[500005];
int c[15][15],nv[65];
vector<pii> v[500005];
int main()
{
 ios::sync_with_stdio(false);
 int n,p;
 cin>>n>>p;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 for(int i=0;i<p;i++)
  c[i][0]=1;
 for(int i=1;i<p;i++)
  for(int j=1;j<=i;j++)
   c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
 for(int i=1;i<=n;i++)
 {
  int cnt=0;
  long long x0=a[i];
  while(x0)
  {
   int x=x0%p;
   x0/=p,cnt++;
   if(x)v[i].emplace_back(x,cnt);
  }
 }
 long long ans=0;
 for(int l=1;l<=n;l++)
 {
  int res=1;
  ans++;
  memset(nv,0,sizeof(nv));
  for(auto i:v[l])
   nv[i.second]=i.first;
  for(int r=l+1;r<=n;r++)
  {
   for(auto i:v[r])
   {
    nv[i.second]+=i.first;
    if(nv[i.second]>=p)
    {
     res=0;
     break;
    }
    res=res*c[nv[i.second]][i.first]%p;
   }
   if(!res)break;
   ans+=res;
  }
 }
 cout<<ans<<endl;
 return 0;
}