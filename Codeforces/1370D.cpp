// Problem : D. Odd-Even Subsequence
// Contest : Codeforces - Codeforces Round #651 (Div. 2)
// URL : https://codeforces.com/contest/1370/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
#include <iostream>
using namespace std;
int n,k;
int a[200005];
bool check(int x,int p)
{
 int cnt=0;
 for(int i=1;i<=n;i++)
  if(!p)
   cnt++,p^=1;
  else if(a[i]<=x)
   cnt++,p^=1;
 return cnt>=k;
}
int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>k;
 for(int i=1;i<=n;i++)
  cin>>a[i];
 int l=1,r=1e9,ans=0;
 while(l<=r)
 {
  int mid=(l+r)>>1;
  if(check(mid,0)||check(mid,1))
   ans=mid,r=mid-1;
  else l=mid+1;
 }
 cout<<ans<<endl;
 return 0;
}