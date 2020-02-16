#include <iostream>
using namespace std;
long long a[1000005],res[1000005];
int main()
{
 ios::sync_with_stdio(false);
 int n,k,ans=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  a[i]+=a[i-1];
 }
 cin>>k;
 for(int i=1;i<=n;i++)
 {
  if(a[i]>=k)break;
  int p=lower_bound(a+1,a+n+1,2*a[i])-a;
  if(p==n+1||a[p]-a[i]>k)
  {
   res[a[i]]++;
   res[k+1]--;
   break;
  }
  res[a[i]]++;
  res[a[p]-a[i]]--;
 }
 for(int i=1;i<=k;i++)
 {
  res[i]+=res[i-1];
  if(res[i])ans++;
 }
 cout<<ans<<endl;
 for(int i=1;i<=k;i++)
  if(res[i])cout<<i<<' ';
 return 0;
}