#include <iostream>
#include <algorithm>
using namespace std;
long long a[45],n,m,resa[1500005],resb[1500005],ans;
void dfs(int l,int r,long long used,long long p[],long long&cnt)
{
 if(used>m)return;
 if(l>r)
 {
  p[++cnt]=used;
  return;
 }
 dfs(l+1,r,used+a[l],p,cnt);
 dfs(l+1,r,used,p,cnt);
}
int main()
{
 cin>>n>>m;
 long long mid=n>>1,cnta=0,cntb=0;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 dfs(1,mid,0,resa,cnta);
 dfs(mid+1,n,0,resb,cntb);
 sort(resa+1,resa+cnta+1);
 for(int i=1;i<=cntb;i++)
  ans+=upper_bound(resa+1,resa+cnta+1,m-resb[i])-resa-1;
 cout<<ans<<endl;
 return 0;
}